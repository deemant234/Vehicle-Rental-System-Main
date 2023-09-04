import mysql.connector
import tkinter as tk
from tkinter import ttk
from datetime import datetime


mydb = mysql.connector.connect(
host='localhost',
user='root',
password='A11789010d0@',
port='3306',
database='veh_rent'
)
my_cursor =mydb.cursor()

win = tk.Tk()
win.geometry("650x250")
# owner_name =tk.StringVar()
# name_label = ttk.Label(win , text='Enter your name')
# name_label.grid(row=0,column=0,sticky=tk.W)
# name_entrybox = ttk.Entry(win, width=16 , textvariable=owner_name)
# name_entrybox.grid(row=0, column=1)
#
# user =tk.StringVar()
# user_label = ttk.Label(win, text='Enter your type rent / user ')
# user_label.grid(row=1,column=0,sticky=tk.W)
# user_entrybox = ttk.Entry(win, width=16 , textvariable=user)
# user_entrybox.grid(row=1,column=1)
#
# aadhar_no =tk.StringVar()
# aadhar_no_label = ttk.Label(win, text='Enter your aadhar number')
# aadhar_no_label.grid(row=2,column=0,sticky=tk.W)
# aadhar_entrybox = ttk.Entry(win, width=16 , textvariable=aadhar_no)
# aadhar_entrybox.grid(row=2,column=1)


# def save() :
#     owner_name_var = owner_name.get()
#     user_var = user.get()
#     aadhar_no_var = aadhar_no.get()
#     str="INSERT INTO common_user VALUES(1,'"+owner_name_var+"',"+aadhar_no_var+",'"+user_var+"');"
#     print(str)
#     my_cursor.execute(str);



#check user
def check_user(name_var,aadhar_no_var,mob_no_var):

    str_query = "SELECT * FROM common_user where name ='" + name_var + "' AND Aadhar_no = " + str(aadhar_no_var) + " AND mob_no = " + str(mob_no_var) + ";"
    my_cursor.execute(str_query)
    label2.destroy()
    label3.destroy()
    label4.destroy()
    label5.destroy()
    name_box.destroy()
    aadhar_no_box.destroy()
    mob_no_box.destroy()
    btn1.destroy()

    rows = my_cursor.fetchall()
    if(len(rows)!=0):
        label6 = ttk.Label(win, text='You are a registered user ')
        label6.grid(row=0,columnspan=3)
        btn2 = ttk.Button(win,text='OK',command=lambda :registered_user_portal(name_var,aadhar_no_var,mob_no_var,label6,btn2))
        btn2.grid(row=1,column=0)

    else:
        cust_portal()

#option table
def registered_user_portal(name_var,aadhar_no_var,mob_no_var,label,btn):
    label.destroy()
    btn.destroy()
    btn2.destroy()
    global label7
    label7 = ttk.Label(win , text='Select from the following options')
    label7.grid(row=0,column=0,sticky=tk.W)

    global  ch_val
    ch_val =tk.IntVar()
    global ch_btn1
    ch_btn1 = ttk.Radiobutton(win , text='Take vehicle on rent ', value=0 , variable=ch_val)
    ch_btn1.grid(row=1,columnspan=3,sticky=tk.W)
    global  ch_btn2
    ch_btn2 = ttk.Radiobutton(win , text='Give vehicle on rent ', value=1 , variable=ch_val)
    ch_btn2.grid(row=2, columnspan=3, sticky=tk.W)
    global ch_btn3
    ch_btn3 = ttk.Radiobutton(win , text='Return vehicle taken on rent ', value=2 , variable=ch_val)
    ch_btn3.grid(row=3, columnspan=3, sticky=tk.W)
    ch_btn4=ttk.Radiobutton(win,text='Pay rent for vehicle',value=3,variable=ch_val)
    ch_btn4.grid(row=4,columnspan=3,sticky=tk.W)
    global submitbtn3
    submitbtn3 = ttk.Button(win , text='Submit' , command=lambda :user_menu_table(name_var,aadhar_no_var,mob_no_var))
    submitbtn3.grid(row=5,column= 0 , sticky=tk.W)



#store vehicle info
def store_veh_info(name_var,aadhar_no_var,mob_no_var,veh_type_var,veh_no_var,join_date_var,label7,label8,label9):
    veh_no.destroy()
    veh_type.destroy()
    join_date.destroy()
    label7.destroy()
    label8.destroy()
    label9.destroy()
    btn4.destroy()
    str_query = "INSERT INTO veh_on_rent_1 VALUES ('"+name_var+"',"+str(aadhar_no_var)+","+str(mob_no_var)+",'"+veh_no_var+"',"+str(veh_type_var)+",date'"+join_date_var+"');"
    my_cursor.execute(str_query)
    str_query2 = "INSERT INTO veh_on_rent_2 (aadhar_no,vehicle_no) VALUES ("+str(aadhar_no_var)+",'"+veh_no_var+"');"
    my_cursor.execute(str_query2)
    global label10
    label10 = ttk.Label(win,text='vehicle info stored successfully\npress OK to close the portal')
    label10.grid(row=0,column=0,sticky=tk.W)
    btn = ttk.Button(win,text='OK',command=close)
    btn.grid(row=1,column=0,sticky=tk.W)


# INSERT INTO `veh_rent`.`veh_on_rent_1`
# (`name`,
# `aadhar_no`,
# `mob_no`,
# `vehicle_no`,
# `vehicle_type`,
# `Date_of_joining`)
# VALUES
# (<{name: }>,
# <{aadhar_no: }>,
# <{mob_no: }>,
# <{vehicle_no: }>,
# <{vehicle_type: }>,
# <{Date_of_joining: }>);

#compare date function
def compare_dates(date1, date2):
    # convert string to date
    dt_obj1 = datetime.strptime(str(date1), "%Y-%m-%d").date()
    dt_obj2 = datetime.strptime(str(date2), "%Y-%m-%d").date()
    if dt_obj1 == dt_obj2:
        return True
    elif dt_obj1 > dt_obj2:
        return True
    else:
        return False
#close function
def close():

    win.quit()

#take vehicle on rent
# INSERT INTO `veh_rent`.`vehicle_user_fd`
# (`aadhar_no`,
# `veh_no`,
# `Date_of_start`,
# `name`,
# `mob_no`,
# `veh_type`)
# VALUES
# (<{aadhar_no: }>,
# <{veh_no: }>,
# <{Date_of_start: }>,
# <{name: }>,
# <{mob_no: }>,
# <{veh_type: }>);

# INSERT INTO `veh_rent`.`veh_user_fd_record`
# (`veh_no`,
# `aadhar_no`,
# `Date_of_start`,
# `expected_date_of_ret`,
# `fare`,
# `actual_date_of_ret`)
# VALUES
# (<{veh_no: }>,
# <{aadhar_no: }>,
# <{Date_of_start: }>,
# <{expected_date_of_ret: }>,
# <{fare: }>,
# <{actual_date_of_ret: }>);


def book_veh(name,aadhar_no,mobile_no,veh_sel_var,date_var_user,end_date_user,day_var,veh_type,label15,btn4):
    # str1="SELECT vehicle_type FROM veh_on_rent_1 WHERE vehicle_no='"+veh_sel_var+"';"
    # my_cursor.execute(str1)
    # res = my_cursor.fetchall()
    # veh_type = res[0]
    # print(str1)
    label15.destroy()
    btn4.destroy()
    str2="INSERT INTO vehicle_user_fd VALUES ( "+str(aadhar_no)+",'"+veh_sel_var+"',date'"+date_var_user+"','"+name+"',"+str(mobile_no)+","+str(veh_type)+","+str(day_var)+");"
    my_cursor.execute(str2)
    strquery="SELECT fare("+str(day_var)+");"
    my_cursor.execute(strquery)
    rows=my_cursor.fetchone()
    str_fare=str(rows)
    str_fare=str_fare.replace("(","")
    str_fare=str_fare.replace(")","")
    str_fare=str_fare.replace(",","")
    str_fare=str_fare.replace("'","")
    str3="INSERT INTO veh_user_fd_record (veh_no,aadhar_no,Date_of_start,expected_date_of_ret,fare) VALUES ('"+veh_sel_var+"',"+str(aadhar_no)+",date'"+date_var_user+"',date'"+end_date_user+"'" \
                                                                                                ","+str_fare+");"
    my_cursor.execute(str3)
    label_text="Congratulations , your ride has been booked\npress OK to close the window\nRETURN THE VEHICLE BY "+end_date_user
    label16=ttk.Label(win,text=label_text)
    label16.grid(rowspan=3,columnspan=3,sticky=tk.W)

    btn5=ttk.Button(win, text='OK',command=close)
    btn5.grid(row=4,column=0,sticky=tk.W)
def check_veh_avail(name,aadhar_no,mobile_no,label10,label11,veh_select_box,veh_sel_var,btn3,date_var_user,label13,box1,day_var,box2,veh_type):
    label10.destroy()
    box2.destroy()
    label13.destroy()
    box1.destroy()
    label11.destroy()
    btn3.destroy()
    veh_select_box.destroy()
    str_query2 = "Select date_add('"+date_var_user+"',INTERVAL "+str(day_var)+" DAY);"
    my_cursor.execute(str_query2)
    res = my_cursor.fetchall()
    end_date_user=str(res[0])
    end_date_user=end_date_user.replace("(","")
    end_date_user=end_date_user.replace(")","")
    end_date_user=end_date_user.replace(",","")
    end_date_user=end_date_user.replace("'","")
    print(end_date_user)
    str_query1 = "SELECT * FROM booking_rec_fd WHERE veh_no = '"+veh_sel_var+"';"
    my_cursor.execute(str_query1)
    rows = my_cursor.fetchall()
    c=False
    if(my_cursor.rowcount!=0):
        for row in rows:
            start_date_var = str(row[0])
            start_date_var=start_date_var.replace("(","")
            start_date_var = start_date_var.replace(")", "")
            start_date_var = start_date_var.replace(",", "")
            start_date_var = start_date_var.replace("'", "")
            end_date_var=str(row[3])
            end_date_var=end_date_var.replace("(","")
            end_date_var = end_date_var.replace(")", "")
            end_date_var = end_date_var.replace(",", "")
            end_date_var = end_date_var.replace("'", "")
            if((compare_dates(date_var_user,start_date_var)) and (compare_dates(end_date_var,date_var_user))):
                c=False
                break
            elif(compare_dates(start_date_var,date_var_user)and (compare_dates(end_date_user,end_date_var))):
                c=False
                break
            elif(end_date_var==None):
                c=False
                break
            else:
                c=True
    else:
        c=True

    if(c):
        str1="Vehicle number "+veh_sel_var+" is available, please return by "+str(end_date_user)+"to avoid fine,press book to confirm "

        label15 = ttk.Label(win,text=str1)
        label15.grid(rowspan=2,columnspan=3)

        btn4=ttk.Button(win,text='Book',command=lambda :book_veh(name,aadhar_no,mobile_no,veh_sel_var,date_var_user,end_date_user,day_var,veh_type,label15,btn4))
        btn4.grid(row=3,column=0,sticky=tk.W)
    else:
        str1="Vehicle number "+veh_sel_var+" is not available at the moment\npress OK to close portal"
        label15 = ttk.Label(win,text=str1)
        label15.grid(rowspan=1,columnspan=3,sticky=tk.W)

        btn4=ttk.Button(win,text='OK',command=close)
        btn4.grid(row=2,column=0,sticky=tk.W)
    # str1="Vehicle number "+veh_sel_var+" is not available at the moment,press OK to close portal"
    # label15 = ttk.Label(win,text=str1)
    # label15.grid(row=0,columnspan=3,sticky=tk.W)
    #
    # btn4=ttk.Button(win,text='OK',command=close)
    # btn4.grid(row=3,column=0,sticky=tk.W)


def avail_veh(name,aadhar_no,mobile_no,label,veh_type_box,veh_type_var,btn4):
    label.destroy()
    btn4.destroy()
    veh_type_box.destroy()
    str_query="SELECT * FROM avail_veh WHERE vehicle_type ="+str(veh_type_var)+";"
    my_cursor.execute(str_query)
    str_query1=""
    rows = my_cursor.fetchall()
    for row in rows:
        str_query1+=str(row)+"\n"
    label10 = ttk.Label(win,text=str_query1)
    label10.grid(rowspan=8,columnspan=4,sticky=tk.W)

    label11 = ttk.Label(win,text='Select vehicle number you want to take on rent')
    label11.grid(row=9,columnspan=5,sticky=tk.W)

    veh_sel_val = tk.StringVar()
    veh_select_box = ttk.Entry(win,width=25, textvariable=veh_sel_val)
    veh_select_box.grid(row=10,column=0,sticky=tk.W)

    label13 = ttk.Label(win, text='Enter date from which vehicle is required')
    label13.grid(row=11, column=0,sticky=tk.W)

    date_val_user = tk.StringVar()
    box1 = ttk.Entry(win, width=25, textvariable=date_val_user)
    box1.grid(row=12, column=0, sticky=tk.W)

    label14 = ttk.Label(win,text='Enter number of days for which vehicle is required')
    label14.grid(row=13,columnspan=3,sticky=tk.W)

    day_val =tk.IntVar()
    box2=ttk.Entry(win,textvariable=day_val)
    box2.grid(row=14,column=0,sticky=tk.W)

    btn3 = ttk.Button(win, text='Submit',command=lambda :check_veh_avail(name,aadhar_no,mobile_no,label10,label11,veh_select_box,(veh_sel_val.get()),btn3,(date_val_user.get()),label13,box1,
    day_val.get(),box2,veh_type_var))
    btn3.grid(row=15,column=0,sticky=tk.W)


def take_veh_on_rent(name,aadhar_no,mobile_no):
    label12 = ttk.Label(win , text='Enter vehicle type required')
    label12.grid(row=0,column=0,sticky=tk.W)

    veh_type = tk.IntVar()
    veh_type_box = ttk.Entry(win , width=25 , textvariable=veh_type)
    veh_type_box.grid(row=0,column=1)

    btn4 = ttk.Button(win,text='Submit type', command=lambda :avail_veh(name,aadhar_no,mobile_no,label12,veh_type_box,veh_type.get(),btn4))
    btn4.grid(row=1,column=0,sticky=tk.W)
#give vehicle on rent
global label7
global label8
global label9

def give_veh_on_rent(name,aadhar_no,mob_no):

    label7 = ttk.Label(win, text='Enter your vehicle type ')
    label7.grid(row=0,column=0)
    global  veh_type_val
    veh_type_val=tk.StringVar()
    global veh_type
    veh_type = ttk.Entry(win,width=25,textvariable=veh_type_val)
    veh_type.grid(row=0,column=1,sticky=tk.W)

    label8 = ttk.Label(win, text='Enter your vehicle number')
    label8.grid(row=1, column=0)
    global veh_no_val
    veh_no_val = tk.StringVar()
    global veh_no
    veh_no = ttk.Entry(win, width=25, textvariable=veh_no_val)
    veh_no.grid(row=1, column=1, sticky=tk.W)

    label9 = ttk.Label(win, text='Enter Date of joining in YYYY-MM-DD ')
    label9.grid(row=2, column=0)
    global join_date_val
    join_date_val = tk.StringVar()
    global join_date
    join_date = ttk.Entry(win, width=25, textvariable=join_date_val)
    join_date.grid(row=2, column=1, sticky=tk.W)

    global btn4
    btn4 = ttk.Button(win ,text='Submit',command=lambda :store_veh_info(name,aadhar_no,mob_no,veh_type_val.get(),veh_no_val.get(),join_date_val.get(),label7,label8,label9))
    btn4.grid(row=3,column = 0,sticky=tk.W)


#return vehicle taken on rent
def veh_ret_final():
    win.destroy()
    label22=ttk.Label(win,text='vehicle has been returned successfully ,\n press close to close the portal')
    label22.grid(row=0,column=0,sticky=tk.W)

    btn_4=ttk.Button(win,text='Close',command=close)
    btn_4.grid(row=2,column=0,sticky=tk.W)

def ret_veh_main(name,aadhar_no,mob_no,veh_var,start_date_var,act_ret_var,label20,act_ret_box,btn):
    label20.destroy()
    btn.destroy()
    act_ret_box.destroy()
    # num_of_day  = my_cursor.callproc('days_calc',start_date_var,act_ret_var)
    str_call_func="SELECT day_calc(date'"+act_ret_var+"',date'"+start_date_var+"');"
    str_query_1="SELECT days FROM vehicle_user_fd WHERE name='"+name+"' AND aadhar_no = "+str(aadhar_no)+" AND mob_no = "+str(mob_no)+" AND veh_no='"+veh_var+"' AND Date_of_start = " \
                                                                                "date'"+start_date_var+"' ;"
    my_cursor.execute(str_query_1)
    num_of_day=my_cursor.fetchall()
    num_of_day=num_of_day[0][0]
    my_cursor.execute(str_call_func)
    row=my_cursor.fetchall()
    res=(row[0][0])
    # res=res.replace("(","")
    # res = res.replace(")", "")
    # res = res.replace(",", "")
    # res = res.replace("'", "")
    # res=int(res)
    day_diff = res - num_of_day
    if(my_cursor.rowcount!=0):
        str_query_2 = "UPDATE veh_user_fd_record SET actual_date_of_ret =date'" + act_ret_var + "' , days_diff = "+str(day_diff)+"  WHERE veh_no='" + veh_var + "' AND aadhar_no=" + str(
            aadhar_no) + " AND Date_of_start =" \
                         "date'" + start_date_var + "' ;"
        my_cursor.execute(str_query_2)
        str_query_3 = "SELECT fare FROM veh_user_fd_record WHERE aadhar_no = "+str(aadhar_no)+" AND veh_no='"+veh_var+"' AND Date_of_start = " \
                                                                                "date'"+start_date_var+"' ;"
        my_cursor.execute(str_query_3)
        fare_final = my_cursor.fetchall()
        str3="updated fare is "+str(fare_final)+"\npress OK to return your vehicle"
        label21 = ttk.Label(win, text=str3)
        label21.grid(rowspan=2,columnspan=1,sticky=tk.W)

        btn3=ttk.Button(win,text='OK',command=veh_ret_final)
        btn3.grid(row = 3,column=0,sticky=tk.W)

def ret_veh(name,aadhar_no,mob_no,veh_var,start_date_var):
    label20=ttk.Label(win,text='Enter date of today in YYYY-MM-DD')
    label20.grid(row=0,column=0,sticky=tk.W)

    act_ret_val = tk.StringVar()
    act_ret_box = ttk.Entry(win,width=25,textvariable=act_ret_val)
    act_ret_box.grid(row=0,column=1)

    btn6=ttk.Button(win,text='Submit',command=lambda:ret_veh_main(name,aadhar_no,mob_no,veh_var,start_date_var,act_ret_val.get(),label20,act_ret_box,btn6))
    btn6.grid(row=1,column=0,sticky=tk.W)
def ret_veh_check(name,aadhar_no,mob_no,veh_var,label18,veh_box,btn5,label19,start_date_var,date_Entry):
    label18.destroy()
    date_Entry.destroy()
    label19.destroy()
    veh_box.destroy()
    btn5.destroy()
    str_query_3="SELECT * FROM booking_rec_fd WHERE veh_no='"+veh_var+"' AND aadhar_no="+str(aadhar_no)+" AND Date_of_start=date'"+start_date_var+"';"

    my_cursor.execute(str_query_3)
    rows=my_cursor.fetchall()
    date_res=str(rows[0][0])
    aadhar_res=(rows[0][1])

    veh_res=str(rows[0][2])
    print("in order")
    print(date_res)
    print(aadhar_res)
    print(veh_res)
    print(start_date_var)
    print(aadhar_no)
    print(veh_var)
    if(my_cursor.rowcount!=0):
        if(date_res==start_date_var and aadhar_res==aadhar_no and veh_res==veh_var ):
            ret_veh(name,aadhar_no,mob_no,veh_var,start_date_var)
        else:
            print("record not found 2")
    else:
        label20 = ttk.Label(win,text='Record not found\npress OK to close the window')
        label20.grid(row=0,column=0,sticky=tk.W)
        btn6=ttk.Button(win,text='OK',command=close)
        btn6.grid(row=1,column=0,sticky=tk.W)

def ret_veh_on_rent(name,aadhar_no,mob_no):
    label18 = ttk.Label(win,text='Enter your vehicle number ')
    label18.grid(row=0,column=0,sticky=tk.W)

    veh_val=tk.StringVar()
    veh_box = ttk.Entry(win,width=25, textvariable=veh_val)
    veh_box.grid(row=0,column=1)

    label19=ttk.Label(win,text='Enter start date ')
    label19.grid(row=1,column=0,sticky=tk.W)

    date_val=tk.StringVar()
    date_Entry = ttk.Entry(win,width=25 , textvariable=date_val)
    date_Entry.grid(row=1,column=1)

    btn5=ttk.Button(win,text='Submit',command=lambda:ret_veh_check(name,aadhar_no,mob_no,veh_val.get(),label18,veh_box,btn5,label19,date_val.get(),date_Entry))
    btn5.grid(row=3,column=0,sticky=tk.W)

#pay rent for vehicle
def pay_rent(name,aadhar,mob_no):

#user menu table
def user_menu_table(name1,aadhar_no1,mobile_no1):
    global ch_user
    ch_user = ch_val.get()
    ch_btn1.destroy()
    ch_btn2.destroy()
    ch_btn3.destroy()
    submitbtn3.destroy()
    label7.destroy()
    btn2.destroy()
    if(ch_user==0):
        take_veh_on_rent(name1,aadhar_no1,mobile_no1)
    elif (ch_user==1):
        give_veh_on_rent(name1,aadhar_no1,mobile_no1)
    elif ch_user==2:
        ret_veh_on_rent(name1,aadhar_no1,mobile_no1)
    else:
        pay_rent(name1,aadhar_no1,mobile_no1)



global label6
label6=ttk.Label(win)
#create user
def createUser():
    name_var = name.get()

    aadhar_no_var = aadhar_no.get()

    mob_no_var = mob_no_val.get()
    label2.destroy()
    label3.destroy()
    label4.destroy()
    label5.destroy()
    name_box.destroy()
    aadhar_no_box.destroy()
    mob_no_box.destroy()
    submitbtn3.destroy()
    str_query="INSERT INTO common_user VALUES('"+name_var+"',"+str(aadhar_no_var)+","+str(mob_no_var)+");"
    my_cursor.execute(str_query)
    label6 = ttk.Label(win, text='Record stored successfully')
    label6.grid(row=0,column=0,sticky=tk.W)
    global  btn1
    btn1 = ttk.Button(win , text='OK',command=lambda :registered_user_portal(name_var,aadhar_no_var,mob_no_var,label6,btn1))
    btn1.grid(row=1,column=0,sticky=tk.W)


#new user

def new_user():
    global label2
    label2 = ttk.Label(win , text='Enter the credentials')
    label2.grid(row=0,column=0,sticky=tk.W)

    global label3
    label3 = ttk.Label(win, text='Enter your name')
    label3.grid(row=1, column=0, sticky=tk.W)

    global name
    name=tk.StringVar()
    global name_box
    name_box = ttk.Entry(win ,width=25 ,  textvariable=name)
    name_box.grid(row=1,column=1)

    global label4
    label4 = ttk.Label(win , text='Enter your aadhar number')
    label4.grid(row=2,column=0,sticky=tk.W)

    global aadhar_no
    aadhar_no = tk.IntVar()
    global aadhar_no_box
    aadhar_no_box = ttk.Entry(win, width=25 , textvariable=aadhar_no)
    aadhar_no_box.grid(row=2,column=1)

    # global label5
    # label5 = ttk.Label(win , text='Select whether you want to take a vehicle on rent or give a vehicle on rent')
    # label5.grid(row=3,column=0)

    # global type_user
    # type_user = tk.StringVar()
    # global  type_user_btn1
    # type_user_btn1 = ttk.Radiobutton(win , text='Take vehicle on rent' , value='user',variable=type_user)
    # type_user_btn1.grid(row=4,column=0,sticky=tk.W)
    # global  type_user_btn2
    # type_user_btn2 = ttk.Radiobutton(win , text='Give vehicle on rent' , value='rent',variable=type_user)
    # type_user_btn2.grid(row=5,column=0,sticky=tk.W)

    global label5
    label5 = ttk.Label(win , text='Enter mobile number')
    label5.grid(row=4,column=0)

    global mob_no_val
    mob_no_val= tk.IntVar()
    global mob_no_box
    mob_no_box = ttk.Entry(win, width=25 , textvariable=mob_no_val)
    mob_no_box.grid(row=4,column=1)
    global submitbtn3
    submitbtn3 = ttk.Button(win , text='Submit',command=createUser)
    submitbtn3.grid(row=6,column=0,sticky=tk.W)


#check user

global btn2

def registered_user():
    global label2
    label2 = ttk.Label(win , text='Enter the credentials')
    label2.grid(row=0,column=0,sticky=tk.W)

    global label3
    label3 = ttk.Label(win, text='Enter your name')
    label3.grid(row=1, column=0, sticky=tk.W)

    global name
    name=tk.StringVar()
    global name_box
    name_box = ttk.Entry(win ,width=25 ,  textvariable=name)
    name_box.grid(row=1,column=1)

    global label4
    label4 = ttk.Label(win , text='Enter your aadhar number')
    label4.grid(row=2,column=0,sticky=tk.W)

    global aadhar_no
    aadhar_no = tk.IntVar()
    global aadhar_no_box
    aadhar_no_box = ttk.Entry(win, width=25 , textvariable=aadhar_no)
    aadhar_no_box.grid(row=2,column=1)
    global label5
    label5 = ttk.Label(win , text='Enter mobile number')
    label5.grid(row=4,column=0)

    global mob_no_val
    mob_no_val= tk.IntVar()
    global mob_no_box
    mob_no_box = ttk.Entry(win, width=25 , textvariable=mob_no_val)
    mob_no_box.grid(row=4,column=1)

    global btn1
    btn1 = ttk.Button(win, text='OK', command=lambda :check_user(name.get(),aadhar_no.get(),mob_no_val.get()))
    btn1.grid(row=5, column=0, sticky=tk.W)




# user_action

def user_action():
    global user_var
    user_var = btn1_val.get()
    btn1.destroy()
    btn2.destroy()
    submitbtn2.destroy()
    label1.destroy()
    if (user_var == 0):
        new_user()
    else:
        registered_user()


#cust_portal

def cust_portal():
    global label1
    label1 = tk.Label(win , text='Select wheteher you are a registered user or a new user')
    label1.grid(row=0,column=0,sticky=tk.W)
    global btn1_val
    btn1_val = tk.IntVar()
    global btn1
    btn1 = tk.Radiobutton(win , text='New User', value=0, variable=btn1_val)
    btn1.grid(row=1,column=0,sticky=tk.W)
    global btn2
    btn2 = tk.Radiobutton(win , text='Registered User', value=1, variable=btn1_val)
    btn2.grid(row=2,column=0,sticky=tk.W)
    global submitbtn2
    submitbtn2 = tk.Button(win, text='Submit' , command=user_action)
    submitbtn2.grid(row=3,column=0,sticky=tk.W)

#admin_portal to be created
def veh_rem_final(veh_var , name):
    label_text="Vehicle number "+veh_var+" owned by "+name+" has been removed successfully,press OK to close the portal"
    label24=ttk.Label(win,text=label_text)
    label24.grid(row=0,columnspan=3,sticky=tk.W)

    btn=ttk.Button(win,text='OK',command=close)
    btn.grid(row=1,column=0,sticky=tk.W)

def veh_rem_main(veh_var,date_end_var):
    str_q="SELECT * FROM veh_on_rent_1 WHERE vehicle_no='"+veh_var+"';"
    my_cursor.execute(str_q)
    rows=my_cursor.fetchall()
    name=str(rows[0][0])
    start_date = str(rows[0][5])
    aadhar_no_user=rows[0][1]
    print("rem veh")
    print(start_date)
    print(name)
    print(aadhar_no_user)
    if(my_cursor.rowcount!=0):
        str_insert="INSERT INTO veh_history (veh_no,date_of_start,date_of_leave) VALUES ('"+veh_var+"',date'"+start_date+"',date'"+date_end_var+"');"
        my_cursor.execute(str_insert)
        str_rem="DELETE FROM veh_on_rent_1 WHERE aadhar_no="+str(aadhar_no_user)+" AND vehicle_no='"+veh_var+"';"
        my_cursor.execute(str_rem)
        str_rem_1="DELETE FROM veh_on_rent_2 WHERE aadhar_no="+str(aadhar_no_user)+" AND vehicle_no='"+veh_var+"';"
        my_cursor.execute(str_rem_1)
        veh_rem_final(veh_var,name)

def remove_veh():
    label2 = ttk.Label(win, text='Enter vehicle number to be removed')
    label2.grid(row=0, column=0, sticky=tk.W)
    veh_val=tk.StringVar()
    veh_box=ttk.Entry(win, width=25,textvariable=veh_val)
    veh_box.grid(row=0,column=1)

    label3 = ttk.Label(win, text='Enter date of today in YYYY-MM-DD')
    label3.grid(row=1, column=0, sticky=tk.W)

    date_end_val = tk.StringVar()
    date_box = ttk.Entry(win, width=25, textvariable=date_end_val)
    date_box.grid(row=1, column=1)

    btn=ttk.Button(win,text='Submit',command=lambda :[label2.destroy(),veh_box.destroy(),label3.destroy(),date_box.destroy(),btn.destroy(),veh_rem_main(veh_val.get(),date_end_val.get())])
    btn.grid(row=2,column=0,sticky=tk.W)

def book_veh_info():
    str_query="SELECT vehicle_user_fd.aadhar_no,vehicle_user_fd.veh_no,veh_user_fd_record.Date_of_start,name,mob_no,veh_type,days,expected_date_of_ret,fare,actual_date_of_ret,days_diff FROM vehicle_user_fd INNER JOIN veh_user_fd_record ON vehicle_user_fd.aadhar_no=veh_user_fd_record.aadhar_no;"
    my_cursor.execute(str_query)
    rows=my_cursor.fetchall()
    for row in rows:
        label6=ttk.Label(win,text=row)
        label6.grid(rowspan=10,column=1,sticky=tk.W)
    label7=ttk.Label(win, text='press OK to close')
    label7.grid(row=11,column=0,sticky=tk.W)

    btn=ttk.Button(win,text='OK',command=close)
    btn.grid(row=13,column=0,sticky=tk.W)

def veh_info():
    str_query="SELECT name,veh_on_rent_1.aadhar_no,mob_no,veh_on_rent_1.vehicle_no,vehicle_type,Date_of_joining,date_of_leave,earning FROM veh_on_rent_1 INNER JOIN veh_on_rent_2 " \
              "ON veh_on_rent_1.aadhar_no=veh_on_rent_2.aadhar_no;"
    my_cursor.execute(str_query)
    rows=my_cursor.fetchall()
    for row in rows:
        label6 = ttk.Label(win, text=row)
        label6.grid(rowspan=10, column=0,sticky=tk.W)
    label7=ttk.Label(win, text='Press OK to close')
    label7.grid(row=12,column=0)

    btn=ttk.Button(win, text='OK',command=close)
    btn.grid(row=13,column=0)

def admn_opt(name,UID,opt_var):
    if(opt_var==0):
        remove_veh()
    elif(opt_var==1):
        book_veh_info()
    elif(opt_var==2):
        veh_info()
def admn_table(name,UID):
    label2=ttk.Label(win,text='Select from the following options')
    label2.grid(row=0,column=0,sticky=tk.W)
    opt_val=tk.IntVar()
    option1=ttk.Radiobutton(win,text='Remove vehicle from list',value=0,variable=opt_val)
    option1.grid(row=1,column=0,sticky=tk.W)

    option2=ttk.Radiobutton(win,text='Information of all booked vehicles',value=1,variable=opt_val)
    option2.grid(row=2,column=0,sticky=tk.W)

    option3=ttk.Radiobutton(win,text='vehicle information',value=2,variable=opt_val)
    option3.grid(row=3,column=0,sticky=tk.W)

    subnit_btn=ttk.Button(win,text='Submit',command=lambda :[label2.destroy(),option1.destroy(),option2.destroy(),option3.destroy(),subnit_btn.destroy(),admn_opt(name,UID,opt_val.get())])
    subnit_btn.grid(row=4,column=0,sticky=tk.W)

def admn_check(name,UID,label20,name_lab,name_box,UID_lab,UID_box,Submit_btn):
    name_box.destroy()
    name_lab.destroy()
    Submit_btn.destroy()
    UID_box.destroy()
    UID_lab.destroy()
    label20.destroy()
    str_qry="SELECT * FROM ADMIN_ACC WHERE UID='"+UID+"';"
    my_cursor.execute(str_qry)
    rows= my_cursor.fetchall()
    print((rows[0][1]))
    if(my_cursor.rowcount!=0):
        if(UID==str(rows[0][1])):
            label21=ttk.Label(win,text='Welcome to Admin portal,press OK to continue')
            label21.grid(row=0,column=0,sticky=tk.W)
            btn3=ttk.Button(win,text='OK',command=lambda :[label21.destroy(),btn3.destroy(),admn_table(name,UID)])
            btn3.grid(row=1,column=0,sticky=tk.W)
    else:
        label21=ttk.Label(win,text='Sorry , we could not find your account ')
        label21.grid(row=0,column=0,sticky=tk.W)
        btn3=ttk.Button(win,text='Retry',command=lambda :[label21.destroy(),btn3.destroy(),admin_portal()])
        btn3.grid(row=1,column=0,sticky=tk.W)
def admin_portal():
    label20=ttk.Label(win,text='Welcome to admin portal , please enter your credentials')
    label20.grid(row=0,column=0,sticky=tk.W)

    name_val=tk.StringVar()
    name_label=ttk.Label(win,text='Enter your name')
    name_label.grid(row=1,column=0,sticky=tk.W)

    name_box=ttk.Entry(win,width=25,textvariable=name_val)
    name_box.grid(row=1,column=1)

    UID_val=tk.StringVar()
    UID_Label=ttk.Label(win,text='Enter your UID')
    UID_Label.grid(row=2,column=0,sticky=tk.W)

    UID_box =ttk.Entry(win , width=25,textvariable=UID_val)
    UID_box.grid(row=2,column=1)

    submit_btn = ttk.Button(win , text='Submit',command=lambda :admn_check(name_val.get(),UID_val.get(),label20,name_label,name_box,UID_Label,UID_box,submit_btn))
    submit_btn.grid(row=3,column=0,sticky=tk.W)

#function cstmr action

def cstmr_action(type_value,admn_login,cust_login,submitbtn1):
    admn_login.destroy()
    cust_login.destroy()
    submitbtn1.destroy()
    if type_value==0 :
        admin_portal()
    else:
        cust_portal()

#
# global admn_login
# admn_login = ttk.Radiobutton(win)
# global cust_login
# cust_login = ttk.Radiobutton(win)
# global submitbtn1
# submitbtn1 = ttk.Button(win)
def Portal():
    type_var = tk.IntVar()
    admn_login = ttk.Radiobutton(win , text = 'Admin' , value = 0 , variable=type_var )
    admn_login.grid(row=2,column=0,sticky=tk.W)
    cust_login = ttk.Radiobutton(win , text='User', value = 1 , variable= type_var)
    cust_login.grid(row=3,column=0,sticky=tk.W)

    #submit button for login type admin/customer

    submitbtn1 = ttk.Button(win, text='Submit' , command=lambda :cstmr_action(type_var.get(),admn_login,cust_login,submitbtn1))
    submitbtn1.grid(row=4,column=1,sticky=tk.W)
Portal()

win.title('GUI')
win.mainloop()
mydb.commit()
mydb.close()

# #create label
# name_label=ttk.Label(win,text='enter your name: ')
# name_label.grid(row=0,column=0,sticky=tk.W)
# age_label=ttk.Label(win, text='enter your age :')
# age_label.grid(row=1,column=0,sticky=tk.W)
# age_var= tk.StringVar()
# age_entrybox = ttk.Entry(win,width=16,textvariable=age_var)
# age_entrybox.grid(row=1,column=1)
#
# gender_label = ttk.Label(win, text='Enter your gender')
# gender_label.grid(row=4 , column=0)
#
# #create combobox
# def gender_action() :
#     user_gender = gender_var.get()
#
# gender_var = tk.StringVar()
# gender_combobox = ttk.Combobox(win, width=16,textvariable=gender_var ,state='readonly', postcommand=gender_action)
# gender_combobox['values']= ('male','female ')
# gender_combobox.grid(row=4,column=1)
# gender_combobox.current(0)
#
# name_var= tk.StringVar()
# name_entrybox = ttk.Entry(win,width=16,textvariable=name_var)
# name_entrybox.grid(row=0,column=1)
# name_entrybox.focus()
#
# radio button
# user_type = tk.StringVar()
# radio_btr1 = ttk.Radiobutton(win , text='student' , value='student' , variable=user_type)
# radio_btr1.grid(row=5 , column=0)
#
# radio_btr2 = ttk.Radiobutton(win , text='teacher ' , value= ' teacher ' , variable=user_type)
# radio_btr2.grid(row=6, column=0)
#
# #check button
# chk_btn_var = tk.IntVar()
# checkbtn1 = ttk.Checkbutton(win , text= 'check if you are a registered user',variable=chk_btn_var )
# checkbtn1.grid(row=7, columnspan=3)
#
# def action():
#     user_name = name_var.get()
#     user_age = age_var.get()
#     user_gender = gender_var.get()
#     user = user_type.get()
#     if chk_btn_var.get()==0:
#         subscribed='NO'
#     else:
#         subscribed='YES'
#     print(user_name,user_age , user_gender ,user,subscribed)
#     name_label.configure(foreground='Blue')
#     name_entrybox.delete(0,tk.END)
#     age_entrybox.delete(0, tk.END)
#
#
# #button
# submit_button = tk.Button(win ,text='submit',command=action)
# submit_button.grid(row=8,column=0,sticky=tk.W)
# submit_button.configure(foreground='Blue')
#

