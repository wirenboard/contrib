#!/usr/bin/env python3

# Test whether a client subscribed to a topic receives its own message sent to that topic.

from mosq_test_helper import *

def write_config(filename, port, persist_file):
    with open(filename, 'w') as f:
        f.write("port %d\n" % (port))
        f.write("allow_anonymous true\n")
        f.write("persistence true\n")
        f.write("persistence_file %s\n" % (persist_file))

port = mosq_test.get_port()
conf_file = os.path.basename(__file__).replace('.py', '.conf')
persist_file = '/tmp/' + conf_file.replace('.conf', '.db')
write_config(conf_file, port, persist_file)

rc = 1
mid = 530
keepalive = 60

connect_packet = mosq_test.gen_connect(
    "persistent-subscription-test", keepalive=keepalive, clean_session=False, proto_ver=5, session_expiry=60
)
connack_packet = mosq_test.gen_connack(rc=0, proto_ver=5)
connack_packet2 = mosq_test.gen_connack(rc=0, flags=1, proto_ver=5)  # session present

subscribe_packet = mosq_test.gen_subscribe(mid, "subpub/qos1", 1, proto_ver=5)
suback_packet = mosq_test.gen_suback(mid, 1, proto_ver=5)

mid = 300
publish_packet = mosq_test.gen_publish("subpub/qos1", qos=1, mid=mid, payload="message", proto_ver=5)
puback_packet = mosq_test.gen_puback(mid, proto_ver=5)

mid = 1
publish_packet2 = mosq_test.gen_publish("subpub/qos1", qos=1, mid=mid, payload="message", proto_ver=5)

if os.path.exists(persist_file):
    os.unlink(persist_file)

broker = mosq_test.start_broker(filename=os.path.basename(__file__), use_conf=True, port=port)

(stdo1, stde1) = ("", "")
try:
    sock = mosq_test.do_client_connect(connect_packet, connack_packet, timeout=20, port=port)
    mosq_test.do_send_receive(sock, subscribe_packet, suback_packet, "suback")

    broker.terminate()
    broker.wait()
    (stdo1, stde1) = broker.communicate()
    sock.close()
    broker = mosq_test.start_broker(filename=os.path.basename(__file__), use_conf=True, port=port)

    sock = mosq_test.do_client_connect(connect_packet, connack_packet2, timeout=20, port=port)

    sock.send(publish_packet)
    mosq_test.receive_unordered(sock, puback_packet, publish_packet2, "puback/publish2")
    rc = 0

    sock.close()
except mosq_test.TestError:
    pass
finally:
    os.remove(conf_file)
    broker.terminate()
    broker.wait()
    (stdo, stde) = broker.communicate()
    if rc:
        print(stde.decode('utf-8'))
    if os.path.exists(persist_file):
        os.unlink(persist_file)


exit(rc)
