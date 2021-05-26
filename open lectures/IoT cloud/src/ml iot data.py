#!/usr/bin/env python
# coding: utf-8

# In[2]:


get_ipython().system('pip install cloudant')


# In[17]:


from cloudant import Cloudant
from cloudant.design_document import DesignDocument
import math
import requests


client = Cloudant('apikey-v2-24g898n6dbzr8esw33oxvb577rn75xwhsv46zewrp8km', 
                  'c5c7bd0def321df5818d59bfd026bd79', 
                  url='https://11cd1b00-26e4-47ce-85e3-b185915a4475-bluemix.cloudantnosqldb.appdomain.cloud', connect=True)

session = client.session()
washing_db = client['washing']
skip = washing_db.doc_count() - 1000
print('len', len)


with DesignDocument(washing_db, 'voltage_doc') as doc:
    view = doc.views['voltage_view_std']
        
    with view.custom_result() as rslt:
        for doc in rslt:
            v_sum = doc['value']['sum']
            v_count = doc['value']['count']
            v_sumsqr = doc['value']['sumsqr']
            v_variance = (v_sumsqr - v_sum ** 2 / v_count) / (v_count - 1)
            v_std = math.sqrt(v_variance)            
            v_zpoint = 1 / v_std
            print(v_sum, v_count, v_sumsqr, v_variance, v_std, v_zpoint)
            if (abs(v_zpoint) > 0.2):
                print('invoke emergency command!')
                r = requests.get("https://node-red-yluux-2021-05-24.mybluemix.net/edgemodelupdate?command=emergencyshutdown")
                r.status_code            
            break



# In[ ]:




