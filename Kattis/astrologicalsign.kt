// Astrological Sign

fun solve(month: String, day: Int) = when {
    month == "Mar" && day >= 21 -> "Aries"
    month == "Apr" && day <= 20 -> "Aries"
    month == "Apr" && day >= 21 -> "Taurus"
    month == "May" && day <= 20 -> "Taurus"
    month == "May" && day >= 21 -> "Gemini"
    month == "Jun" && day <= 21 -> "Gemini"
    month == "Jun" && day >= 22 -> "Cancer"
    month == "Jul" && day <= 22 -> "Cancer"
    month == "Jul" && day >= 23 -> "Leo"
    month == "Aug" && day <= 22 -> "Leo"
    month == "Aug" && day >= 23 -> "Virgo"
    month == "Sep" && day <= 21 -> "Virgo"
    month == "Sep" && day >= 22 -> "Libra"
    month == "Oct" && day <= 22 -> "Libra"
    month == "Oct" && day >= 23 -> "Scorpio"
    month == "Nov" && day <= 22 -> "Scorpio"
    month == "Nov" && day >= 23 -> "Sagittarius"
    month == "Dec" && day <= 21 -> "Sagittarius"
    month == "Dec" && day >= 22 -> "Capricorn"
    month == "Jan" && day <= 20 -> "Capricorn"
    month == "Jan" && day >= 21 -> "Aquarius"
    month == "Feb" && day <= 19 -> "Aquarius"
    month == "Feb" && day >= 20 -> "Pisces"
    month == "Mar" && day <= 20 -> "Pisces"
    else -> TODO()
}

fun main() {
    repeat(readLine()!!.toInt()) {
        val(day, month) = readLine()!!.split(" ")
        println(solve(month, day.toInt()))
    }
}