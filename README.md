# TP-SERE

### Step 1
Open 2 Terminal windows in this folder

### Step 2
Compile both files:
gcc -o server -fno-stack-protector -m32 -z execstack server.c
gcc -o client -fno-stack-protector -m32 -z execstack client.c

### Step 3
In one terminal:
  ./server [PORT]
Another terminal:
  ./client 0 [PORT]
Where PORT is a random port you choose between 1024 and 64000

### Step 4
The initial password_size is set at 8 characters
To be able to overflow the variable length and override the password value you need to write in the field a password that has at least password_size+1 characters and at max password_size+(password_size-2) characters
The new password would be starting from character password_size+1 until password_size+(password_size-2)
For instance, if you write 01234567XXXXX, the new password set would XXXXX

### Note
In case you get binding error, just change the port number
