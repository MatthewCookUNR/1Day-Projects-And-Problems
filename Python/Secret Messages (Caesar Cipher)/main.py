#Function takes in a string message and an integer used for encryption
#Underlying algorithm is the ancient Caesar Cipher, which involved 
#shifting the letters of alphabet by a given index. When you take the
#encrypted message and shift the letters with the reverse of the key,
#the original message is deciphered (Ex. 1 Encrypt and then -1 Decrypt)

def secretMessages(message, cipherKey):
  if len(message) > 0:
    secretList = list(message)
    for i in range(len(message)):
      #Case 1: Capital Letter
      if secretList[i] >= 'A' and secretList[i] <= 'Z':
        intCon = ord(secretList[i])
        intCon += cipherKey
        secretList[i] = chr(intCon)
        if secretList[i] > 'Z':
          #Add key to the secret list item by converting to int,
          #adding key, and finally converting back to str
          intCon = ord(secretList[i])
          intCon -= 26
          secretList[i] = chr(intCon)
        elif secretList[i] < 'A':
          intCon = ord(secretList[i])
          intCon += 26
          secretList[i] = chr(intCon)
      #Case 2: Lowercase letter
      elif secretList[i] >= 'a' and secretList[i] <= 'z':
        intCon = ord(secretList[i])
        intCon += cipherKey
        secretList[i] = chr(intCon)
        if secretList[i] > 'z':
          intCon = ord(secretList[i])
          intCon -= 26
          secretList[i] = chr(intCon)
        elif secretList[i] < 'a':
          intCon = ord(secretList[i])
          intCon += 26
          secretList[i] = chr(intCon)
      #Case 3: Number
      elif secretList[i] >= '0' and secretList[i] <= '9':
        #Since only 10 numbers, take mod 10 of key so that it is
        #from 0 to 10 instead
        numShift = cipherKey % 10
        intCon = ord(secretList[i])
        intCon += numShift
        secretList[i] = chr(intCon)
        if secretList[i] > '9':
          intCon = ord(secretList[i])
          intCon -= 10
          secretList[i] = chr(intCon)
        elif secretList[i] < '0':
          intCon = ord(secretList[i])
          intCon += 10
          secretList[i] = chr(intCon)
    return "".join(secretList)
  else:
    return "String is empty"

message = input("Please enter in a number to be encrypted/decrypted:")
cipherKey = int(input("Please enter the desired key:"))
print (secretMessages(message, cipherKey))