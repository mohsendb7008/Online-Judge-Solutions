var N = 0
val indices = Array(200003){ArrayList<Int>()}

val fenwick1 = IntArray(200003){0}

fun rsq1(i: Int): Int{
    var ans = 0
    var it = i
    while(it != 0){
        ans += fenwick1[it]
        it -= (it and (-it))
    }
    return ans
}

fun inc1(i: Int, k: Int){
    var it = i
    while(it <= N){
        fenwick1[it] += k
        it += (it and (-it))
    }
}

val fenwick2 = IntArray(200003){0}

fun rsq2(i: Int): Int{
    var ans = 0
    var it = i
    while(it != 0){
        ans += fenwick2[it]
        it -= (it and (-it))
    }
    return ans
}

fun inc2(i: Int, k: Int){
    var it = i
    while(it <= N){
        fenwick2[it] += k
        it += (it and (-it))
    }
}

val red = ArrayList<Int>()
val green = ArrayList<Int>()

fun main() {
    N = readLine()!!.toInt()
    val line = readLine()!!.split(" ").map { it.toInt() }
    for(i in line.indices)
        indices[line[i]].add(i + 1)
    var it = 1
    while(indices[it].size == 2){
        if(rsq1(indices[it][0]) != rsq2(indices[it][1]))
            break
        inc1(indices[it][0], 1)
        inc2(indices[it][1], 1)
        red.add(indices[it][0])
        green.add(indices[it][1])
        it++
    }
    val ans = CharArray(N){'B'}
    for(r in red)
        ans[r-1] = 'R'
    for(g in green)
        ans[g-1] = 'G'
    println(ans.joinToString(separator = ""))
}