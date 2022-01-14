# Saving Daylight

def daylight(sunrise: str = '6:24', sunset: str = '20:37'):
    seconds = lambda t: int(t.split(':')[0]) * 60 + int(t.split(':')[1])
    dl = seconds(sunset) - seconds(sunrise)
    return dl // 60, dl % 60

if __name__ == '__main__':
    while True:
        try:
            month, day, year, sunrise, sunset = input().split()
            hours, minutes = daylight(sunrise, sunset)
            print(f'{month} {day} {year} {hours} hours {minutes} minutes')
        except EOFError:
            break