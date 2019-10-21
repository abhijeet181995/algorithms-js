//function to right rotate the array
void right_rotate(vector<string>&s,int i,int j)
{
    string temp = s[j];
    for (int k=j;k>i;k--){
        s[k]=s[k-1];
    }
    s[i]=temp;
    return;
}
//function to left rotate the array
void left_rotate(vector<string>&s,int i,int j)
{
    string temp = s[i];
    for (int k=i;k<j;k++){
        s[k]=s[k+1];
    }
    s[j]=temp;
    return;
}
int cnt=0;// to count the no's of permutations generated yet
void permute( vector<string>s,int i,int k,string &ans){
    if (cnt>k){
        return;
    }
    if (i==s.size()){
        cnt+=1;
        if (cnt==k){
           for(int j=0;j<s.size();j++)
           ans+=s[j];
        }
        return;
    }
    permute(s,i+1,k,ans);
    for (int j=i+1;j<s.size();j++){
        right_rotate(s,i,j);
        permute(s,i+1,k,ans);
        left_rotate(s,i,j);
    }
}
