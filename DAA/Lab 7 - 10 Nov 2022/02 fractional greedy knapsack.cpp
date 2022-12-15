// O(NlogN)

/*
Sort objects in descending order of profit/weight ratio.
capacityLeft = totalCapactiy
for(object in objects)
    if(capacityLeft == 0) store 0*profit for that obj
    else if(objectWeight <= capacityLeft) store 1*profit for that obj
    else store (capacityLeft/objectWeight)*profit for that obj
*/