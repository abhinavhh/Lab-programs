#include<stdio.h>
void main(){

    //Declare intiger variables
    int incoming,outgoing,bucketsize,n,store=0;

    //read values for bucketsize , outgoing-rate , no of inputs 
    printf("\nEnter the bucketsize , outgoing rate and no of inputs : ");
    scanf("%d %d %d",&bucketsize,&outgoing,&n);

    //check while condtion
    while(n-- !=0){

        //read the incoming packet size
        printf("\nEnter the incoming packet size: ");
        scanf("%d",&incoming);

        //check if incoming is less than bucketsize - store
        if(incoming <= (bucketsize - store)){

            //add incoming to store 
            store += incoming;
            printf("\nBucket buffer size is %d out of %d",store,bucketsize);
        }
        else{

            //calculate dropped packets
            int dropped = incoming - (bucketsize - store);
            printf("\nDropped %d no of packets",dropped);

            store = bucketsize;
            printf("\nBucket buffer size is %d out of %d",store,bucketsize);
        }

        //update store value after outgoing
        store -= outgoing;
    }
    if(store < 0){
        store = 0;
        printf("\nAfter outgoing 0 packets are left out of %d in buffer",bucketsize);
    }
}