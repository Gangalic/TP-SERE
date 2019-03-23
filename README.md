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
Answer the questions and lets see how it goes after
