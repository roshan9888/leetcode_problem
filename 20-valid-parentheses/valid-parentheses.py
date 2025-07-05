class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        for ch in s:
            if ch in '([{':
                st.append(ch)
            else:
                if not st:
                    return False
                if ord(st[-1])+1==ord(ch) or ord(st[-1])+2==ord(ch):
                    st.pop()
                else:
                    return False

        
        return not st 