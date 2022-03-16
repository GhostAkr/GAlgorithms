from string import punctuation

def longest_word_in_file(file_name):
    """
        Return word with max length in file. Any punctuation symbols are excluded from file.
    """
    f = open(file_name, encoding = 'utf-8')
    words = f.read().split()
    max_word = ''
    for word_ix in range(len(words)):
        word = words[word_ix]
        clear_word = ''
        for letter in word:
            if letter not in punctuation:
                clear_word += letter
        if len(clear_word) >= len(max_word):
            max_word = clear_word

    return max_word
