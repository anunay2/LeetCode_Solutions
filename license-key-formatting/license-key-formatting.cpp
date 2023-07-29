class Solution {
public:
    char ToCapsIfAlphaBet( char ch ) {
	    if ( ch>='a' && ch<='z'){
		    ch  = ch - ('a' - 'A');
        }	
	    return ch;

    }

string licenseKeyFormatting(string key, int k) {
	int i = key.size() - 1, groupSizeCovered = k;
	string formattedKey = "";
	while ( i >= 0 ) {
		if ( key[i] != '-') {
			if( groupSizeCovered == 0 ) {
				groupSizeCovered = k;
                formattedKey.push_back('-');
				//formattedKey= '-' + formattedKey;
			}
			groupSizeCovered --;
			formattedKey.push_back(ToCapsIfAlphaBet(key[i]));
		}
		i--;
	}
	reverse(formattedKey.begin(),formattedKey.end());
    return formattedKey;
    }
};