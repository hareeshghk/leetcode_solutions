class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        paths = path.split("/")
        
        changesPaths = []
        
        for path in paths:
            if path == "." or path == "":
                continue
            elif path == "..":
                if len(changesPaths) > 0:
                    changesPaths = changesPaths[:-1]
            else:
                changesPaths.append(path)
                
        answer = ""
        
        if len(changesPaths) == 0:
            return "/"
        
        for path in changesPaths:
            answer += "/"+path
            
        return answer
        