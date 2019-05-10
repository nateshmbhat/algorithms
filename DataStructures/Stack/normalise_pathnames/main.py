stk = []
path = "sc/././../tmk/awk/../../hi/howru" ; 

if path[0]=='/':
    stk.append('/') 

for token in path.split('/'):
    if(token=='..'):stk.pop() ; 
    elif(token=='.'): pass ; 
    else : stk.append(token) ; 

print("/".join(stk)) ; 