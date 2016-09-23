def dec2bin(x):
    """Return a string with binary sequence of x"""

    masc = 1
    result = ""

    for i in range(x.bit_length()):
        result += '1' if masc & x else '0'
        masc = masc << 1

    return result[::-1].lstrip('0')


def validates_dec2bin(x):
    """Validades the dec2bin function"""

    return True if bin(x)[2:] == dec2bin(x) else False
