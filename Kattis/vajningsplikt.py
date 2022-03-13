# Right-of-Way

def whenSouth(b, c):
    return 'Yes' if ((b == 'North' and c == 'East') or (b == 'West' and c in ['North', 'East'])) else 'No'


if __name__ == '__main__':
    a, b, c = input().split()
    tr = {
        'South': {
            'South': 'South',
            'North': 'North',
            'East': 'East',
            'West': 'West'
        },
        'North': {
            'South': 'North',
            'North': 'South',
            'East': 'West',
            'West': 'East'
        },
        'East': {
            'South': 'West',
            'North': 'East',
            'East': 'South',
            'West': 'North'
        },
        'West': {
            'South': 'East',
            'North': 'West',
            'East': 'North',
            'West': 'South'
        }
    }[a]
    print(whenSouth(tr[b], tr[c]))