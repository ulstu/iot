import json
import time
import paho.mqtt.client as mqtt

device_token = "8*Y?YrelkALK)7jfDy"
use_token_auth = "use-token-auth"
org_id = "aev2o9"
app_id = "iotlab51"
device_type = "IOT"
device_name = "type1"

client = mqtt.Client('d:{}:{}:{}'.format(org_id, device_type, device_name))

client.username_pw_set(use_token_auth, device_token)
result = client.connect('{}.messaging.internetofthings.ibmcloud.com'.format(org_id), 1883, 60)
temp = 20
try:
    while (True):
        payload = {'d': {'temperature': temp}}
        temp = 1 if temp % 900 == 0 else temp + 1
        res = client.publish('iot-2/evt/statusEvent/fmt/json', json.dumps(payload))
        print('published temperature {} {}'.format(temp, res))
        time.sleep(1)
except:
    client.disconnect()
    print('interrupted')
