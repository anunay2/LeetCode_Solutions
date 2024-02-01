import java.util.HashSet;
import java.util.Set;

public class UniqueMail {
    public int numUniqueEmails(String[] emails) {
        Set<String> hashset = new HashSet<>();
        for( String email : emails) {
            StringBuilder domainName = new StringBuilder();
            int i = 0;
            boolean plusSignFound = false;
            while (i < email.length()){
                if (email.charAt(i) == '@') {
                    break;
                }
                if (email.charAt(i) == '+') {
                    plusSignFound = true;
                }
                else if ( !plusSignFound && email.charAt(i)!='.') {
                    domainName.append(email.charAt(i));
                }
                i++;
            }
            String restOfTheEmail = email.substring(i+1);
            String formedEmail = domainName + restOfTheEmail;
            hashset.add(formedEmail);
    }
    return hashset.size();
}
