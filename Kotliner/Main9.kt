fun main() {
    val (n, k, l) = readln().split(" ").map { it.toInt() }
    val d = readln().split(" ").map { it.toInt() }
    var tank = k
    var ans = 0
    val stations = ArrayList<Int>()
    if (d[0] > tank) {
        println(-1)
        return
    }
    tank -= d[0]
    for (i in 1..<n) {
        if (d[i] - d[i-1] > tank) {
            if (d[i] - d[i-1] > k) {
                println(-1)
                return
            }
            tank = k - (d[i] - d[i-1])
            ans++
            stations.add(i)
        } else {
            tank -= d[i] - d[i-1]
        }
    }
    if (l - d[n-1] > tank) {
        if (l - d[n-1] > k) {
            println(-1)
            return
        }
        ans++
        stations.add(n)
    }
    println(ans)
    println(stations.joinToString(" "))
}