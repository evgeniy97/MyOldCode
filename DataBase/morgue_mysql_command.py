def add_body(dictionary):
    #print("INSERT INTO body VALUES ({number},{sex}, '{surname}', '{name}', '{date_arrived}', '{date_birth}','{date_death}', {id_insurable});".format(**dictionary))
    Cursor.execute("INSERT INTO body VALUES ({number},{sex}, '{surname}', '{name}', '{date_arrived}', '{date_birth}','{date_death}', {id_insurable});".format(**dictionary))
    for i in Cursor:
        print(i)

def delete_body(dictionary):
    command = "DELETE FROM body WHERE id_body={number}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body(dictionary):
    command = "SELECT * FROM body WHERE date_arrived = '{date}' ".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_not_equale(dictionary):
    command = "SELECT * FROM body WHERE date_arrived != date_death ".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_between(dictionary):
    command = "SELECT * FROM body WHERE date_death BETWEEN '{date1}' AND '{date2}'".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_before(dictionary):
    command = "SELECT * FROM body WHERE date_birth < '{date}'".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_after(dictionary):
    command = "SELECT * FROM body WHERE date_birth > '{date}'".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def add_doctor(dictionary):
    command = "INSERT INTO pathologist VALUES({number},{id_morgue},'{surname}','{name}','{phone}','{addres}')".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)


def delete_doctor(dictionary):
    command = "DELETE FROM pathologist WHERE id_doctor={number}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def add_card(dictionary):
    command = "INSERT INTO card VALUES({id_body},{id_diagnosis},{id_doctor})".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def delete_card(dictionary):
    command = "DELETE FROM card WHERE (id_body={id_body} AND id_diagnosis = {id_diagnosis})".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_insurable(dictionary):
    command = "SELECT * FROM body WHERE id_insurable = '{id_insurable}'".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_insurable(dictionary):
    # SECET можно доделать
    command = "SELECT body.id_body, body.surname, body.name, insurable.name FROM body LEFT JOIN insurable ON body.id_insurable = insurable.id_insurable".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def show_body_doctor(dictionary):
    command = "SELECT body.id_body, body.surname, body.name FROM body LEFT JOIN card ON body.id_body = card.id_body WHERE card.id_doctor = {id_doctor} ".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

# Вывести все диагнозы конкретного тела
def show_body_diagnosis(dictionary):
    #command = "SELECT body.id_body,body.surname, body.name, diagnosis.name FROM (body LEFT JOIN card ON body.id_body = card.id_body) LEFT JOIN diagnosis ON card.id_diagnosis = diagnosis.id_diagnosis WHERE card.id_body = {id_body}".format(**dictionary)
    command = "SELECT diagnosis.name FROM card LEFT JOIN diagnosis ON diagnosis.id_diagnosis = card.id_diagnosis WHERE card.id_body = {id_body}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

# Вывести все тела с конкретным диагнозом 
def show_body_with_corrent_diagnosis(dictionary):
    command = "SELECT body.id_body, body.name, body.surname FROM card LEFT JOIN body ON card.id_body = body.id_body WHERE card.id_diagnosis = {id_diagnosis}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def doctors_from_morgue(dictionary):
    command = "SELECT pathologist.id_doctor, pathologist.name, pathologist.surname FROM pathologist WHERE id_morgue={id_morgue}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)

def all_diagnosis_from_doctor(dictionary):
    command = "SELECT diagnosis.name FROM card LEFT JOIN diagnosis ON card.id_diagnosis = diagnosis.id_diagnosis WHERE id_doctor={id_doctor}".format(**dictionary)
    print(command)
    Cursor.execute(command)
    for i in Cursor:
        print(i)