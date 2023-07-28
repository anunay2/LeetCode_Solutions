class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       unordered_set<string>  validEmail;
	    for ( string email : emails ){
            int i = 0;
            string tempMail = "";
            bool encountedPlus = false;
            while(   email[ i ]  !=  '@'  ) {
                if( email[i]=='+'){
                    encountedPlus = true;
                }
                if( !encountedPlus  && email[i] != '.' ){
                    tempMail += email[i];
                }
                i++;
                
            }
            while( i<email.size()){
                tempMail += email[i];
                i++;
            }
            if( tempMail.size()>0 ){
                validEmail.insert(tempMail);
            }
	}
	    return validEmail.size();

    }
};