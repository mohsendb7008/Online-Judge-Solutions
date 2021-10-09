fun f(x: Int): Int {
    var y = x + 1
    while (y > 0 && y % 10 == 0) {
        y /= 10
    }
    return y
}

fun main() {
    var n = readLine()!!.toInt()
    val set = HashSet<Int>()
    set.add(n)
    while (true) {
        n = f(n)
        if (set.contains(n))
            break
        set.add(n)
    }
    println(set.size)
}