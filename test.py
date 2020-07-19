# -*- coding: utf-8 -*-
"""
Created on Fri Apr 19 19:53:42 2019

@author: distroter
"""





import MySQLdb
conn = MySQLdb.connect(user="root", passwd="rishi26071997", db="rishi")
cur = conn.cursor()
cur.execute("select Pwd from Credentials where userid = \"Abhay\" ;")
row = cur.fetchone()
conn.commit()
cur.close()
conn.close()

