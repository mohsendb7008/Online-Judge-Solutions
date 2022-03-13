// Toilet Seat

fun main(){
    val seats = readLine()!!
    println(2 * seats.drop(1).count { c -> c == 'D' } + if (seats[0] == 'D') (if (seats[1] == 'D') -1 else 1) else 0)
    println(2 * seats.drop(1).count { c -> c == 'U' } + if (seats[0] == 'U') (if (seats[1] == 'U') -1 else 1) else 0)
    println(seats.withIndex().count { it.index > 0 && seats[it.index - 1] != it.value })
}