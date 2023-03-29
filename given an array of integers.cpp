int countDuplicate(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int count=0,f=0;
    for(int i=1;i<numbers.size();i++)
    {
        if((numbers[i]==numbers[i-1])&&f==0){
            count++;
            f=1;
        }
        if(numbers[i]!=numbers[i-1])
        f=0;
    }
    return count;