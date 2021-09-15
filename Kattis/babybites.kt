// Baby Bites

fun solveForBaby(numbers: List<String>): String {
    for(i in 0 until numbers.size)
        if(numbers[i] != "mumble" && numbers[i].toInt() != i + 1)
            return "something is fishy"
    return "makes sense"
}

fun main() {
    readLine()
    println(solveForBaby(readLine()!!.split(" ")))
}