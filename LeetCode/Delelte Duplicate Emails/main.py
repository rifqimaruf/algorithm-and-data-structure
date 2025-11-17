import pandas as pd
import sqlite3

data = [[1, 'john@example.com'], [2, 'bob@example.com'], [3, 'john@example.com']]
person_df = pd.DataFrame(data, columns=['id', 'email']).astype({'id': 'int64', 'email':'object'})


# sqlite connection
conn = sqlite3.connect(':memory:')

person_df.to_sql('Person', conn, if_exists='replace', index=False)
print(pd.read_sql('SELECT * FROM Person', conn))

# delete duplicates
with open('delete_duplicates.sql', 'r') as file:
    sql_query = file.read()
conn.executescript(sql_query)

print(pd.read_sql('SELECT * FROM Person', conn))