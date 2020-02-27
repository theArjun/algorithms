"""
Title : Generate Subsets in a Given Approach
Author :  Arjun Adhikari
Approach Used : Binary Number Form; O(2^n) complexity
"""

def generateSubsets(arr):

    """  2020 Feb 27 Thu  19:10:00 - Arjun Adhikari
    There are 2^n subsets in array of n elements.  """
    subset_len = 2**(len(arr))
    subset_dict = [bin(num).replace("0b", "") for num in range(subset_len)]

    for subset_bin in subset_dict:
        print('{', end='')
        for i in range(len(subset_bin)):
            if subset_bin[i] == '0':
                continue
            elif subset_bin[i] == '1':
                print(arr[i], end=', ')
        print('} ')


if __name__ == "__main__":

    arr = [1, 2, 3, 4, 5, 6, 7, 8]
    generateSubsets(arr)
