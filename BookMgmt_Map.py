def insert(map):
    id=input("\nEnter the Id of the Book: ")
    name=input("\nEnter the Name of the Book: ")
    for x in map.keys():
        if(x==id):
            print("\nThe Id already exists in the list!!\n")
            return
    map[id]=name

def remove(map):
    if len(map)==0:
        print("\nNo Books to delete!!!")
        return
    id=input("\nEnter the ID of the book to delete: ")
    for x in map.keys():
        if(x==id):
            print(f"\n{map[id]} is removed from the list!!\n")    
            del map[id]
            return
    print("\nEntered Id Does not Exist!!\n")
    
    
def search(map):
    if len(map)==0:
        print("\nThere are no books in the List!!!")
        return
    try:
        id=input("\nEnter the Id of the Book to search: ")
        print(f"\nID: {id}\t Name: {map[id]}")
    except:
        print("\nBook Id does not exist in the list!!!")


def display(map):
    if len(map)==0:
        print("\nThere are no books in the List!!!")
        return
    for y in map.keys():
        print(f"\n{y}\t{map[y]}")
        
    
map=dict()
id=0

while(1):
    opt=int(input("\n1.Insert Book\n2.Remove Book\n3.Display Books\n4.Search\n5.Exit\n\nPlease Enter your Choice:  "))

    if(opt==1):
        insert(map)
        
    elif(opt==2):
        remove(map)
        
    elif(opt==3):
        display(map)
        
    elif(opt==4):
        search(map)
        
    elif(opt==5):
        break

    else:
        print("\nPlease Enter a Appropriate Option!!!!")
