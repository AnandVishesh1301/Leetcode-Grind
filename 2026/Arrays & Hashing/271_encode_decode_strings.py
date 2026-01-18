class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_str = ""
        encoder = ";" + str(ord(';'))
        for word in strs:
            encoded_str += str(word) + encoder
        return encoded_str

    def decode(self, s: str) -> List[str]:
        decoded_str = []
        word = ""
        encoder = ";" + str(ord(';'))
        res = s.split(encoder)
        null_str = res.pop()
        
        return res


