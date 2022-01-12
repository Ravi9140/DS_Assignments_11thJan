text=input("\nEnter Text: ")
text=text.lower()     
word=text.split(' ')  #remove whitespaces

dict1=dict()     
newlist=list()   

#to make a new newlist removing terminating ',' and '.' and '\n' character
for x in word:  
    if x=='':   
        continue
    elif (x[-1]=='.' or x[-1]==',' or x[-1]=='\n'):
        newlist.append(x[0:-1])
    else:
        newlist.append(x[0:])
        
key=dict1.keys()

for x in newlist: 
    if x in key:
        count=dict1[x]   #to store the previous count of the word
        dict1[x]=count+1
    else:
        dict1[x]=1

try:
    str=input("\nEnter word to Check Occurence: ")
    print(f"\nOccurence of {str} is {dict1[str]}")
except:
    print(f"\nOccurence of word {str} is 0!!!")
