def check_registration_rules(**kwargs):
    return list(dict(filter(lambda x: len(x[1]) >= 6 and len(x[0]) >= 4 and x[0] != 'quera' and x[0] != 'codecup' and not x[1].isdigit(), kwargs.items())))