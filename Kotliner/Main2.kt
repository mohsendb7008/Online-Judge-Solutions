fun main() {
    val n = readln().toInt()
    var ans = 0
    for (i in 1..<n)
        for (j in i..<n)
            for (k in j..<n)
                if (i + j + k == n && i + j > k && i + k > j && j + k > i)
                    ans++
    println(ans)
}