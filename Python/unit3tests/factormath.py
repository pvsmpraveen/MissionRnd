def get_hcf(first,second):
    result = []
    d1 = dict(first)
    d2 = dict(second)

    for key in d1:
        if(key in d2):
            result.append((key,min(d1[key],d2[key])))

    return sorted(result)

def get_lcm(first,second):
    result = []
    d1 = dict(first)
    d2 = dict(second)

    for key in d1:
        if(key in d2):
            result.append((key,max(d1[key],d2[key])))
        else:
            result.append((key,d1[key]))
    for key in d2:
        if(key not in d1):
            result.append((key,d2[key]))

    return sorted(result)

def multiply(first,second):
    result = []
    d1 = dict(first)
    d2 = dict(second)

    for key in d1:
        if (key in d2):
            result.append((key,d1[key]+ d2[key]))
        else:
            result.append((key, d1[key]))
    for key in d2:
        if (key not in d1):
            result.append((key, d2[key]))

    return sorted(result)