// O(n)

/*
Create a set A and add a1 to it
last=1
for(i=2 to total activites)
    if(starting time of ai >= finishing time of alast)
        last=i
        A = A union ai
return A
*/