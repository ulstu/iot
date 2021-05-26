# Исходник по связи приложения платы с облаком IBM

# Подключаем библиотеки
import json
import time
import paho.mqtt.client as mqtt

# Указываем токен созданного устройства (генерируется автоматически в IBM Cloud при создании устройства.
device_token = "IFMfqzwib-Q3JL8FF0"
use_token_auth = "use-token-auth"
# Указываем id организации, которую мы создали, отображается в правом верхнем углу.
org_id = "aev2o9"
# id созданного приложения
app_id = "iotlab17122020"
# Копируем тип созданного устройства из панели IBM Cloud
device_type = "simple_device_type"
# Так же поступаем с именем устройства
device_name = "simple_device_1"

# Устанавливаем параметры подключения клиента
client = mqtt.Client('d:{}:{}:{}'.format(org_id, device_type, device_name))
client.username_pw_set(use_token_auth, device_token)
# Указываем параметры для подключения к IBM Cloud, id организации и порт подключения(стандартный 1883)
result = client.connect('{}.messaging.internetofthings.ibmcloud.com'.format(org_id), 1883, 60)
temp = 20
# Пробуем подключиться
try:
    while (True):
	# Передаем переменной payload в качестве данных ключ temperature и значение, находящееся на данной 		итерации в переменной temp
        payload = {'d': {'temperature': temp}}
	# Увеличиваем переменную на единицу, пока целочисленный остаток от деления значения 		  		переменной temp на 900 не станет равен 0, т.е пока temp не станет равен 900.
        temp = 1 if temp % 900 == 0 else temp + 1
	# Публикуем значение параметра температуры в топик iot-2/evt/statusEvent/fmt/json
        res = client.publish('iot-2/evt/statusEvent/fmt/json', json.dumps(payload))
	# Выводим результат в консоль приложения
        print('published temperature {} {}'.format(temp, res))
	# Ждем 1 секунду
        time.sleep(1)
# В случае исключений разрываем соединение и выводим в консоль, что операция прервана.
except:
    client.disconnect()
    print('interrupted')

# https://www.ibm.com/support/knowledgecenter/SSQP8H/iot/platform/applications/mqtt.html
