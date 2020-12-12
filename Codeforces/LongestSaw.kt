var n = 0
lateinit var a: MutableList<Int>
val b = ArrayList<Int>()

fun isSaw(): Boolean{
    var ans = true
    for(i in 1 until b.size){
        if(i % 2 == 0 && b[i] <= b[i-1]){
            ans = false
            break
        }
        if(i % 2 == 1 && b[i] >= b[i-1]){
            ans = false
            break
        }
    }
    if(ans)
        return true
    for(i in 1 until b.size){
        if(i % 2 == 1 && b[i] <= b[i-1])
            return false
        if(i % 2 == 0 && b[i] >= b[i-1])
            return false
    }
    return true
}

fun saw(l1: Int, l2: Int): Boolean{
    b.clear()
    var(ptrl, ptrr, i) = listOf(0, n-l2, 0)
    while(ptrl < l1 || ptrr < n){
        when {
            ptrl == l1 -> b.add(a[ptrr++])
            ptrr == n -> b.add(a[ptrl++])
            i % 2 == 0 -> b.add(a[ptrl++])
            else -> b.add(a[ptrr++])
        }
        i++
    }
    if(isSaw())
        return true
    b.clear()
    ptrl = 0
    ptrr = n-l2
    i = 0
    while(ptrl < l1 || ptrr < n){
        when {
            ptrl == l1 -> b.add(a[ptrr++])
            ptrr == n -> b.add(a[ptrl++])
            i % 2 == 1 -> b.add(a[ptrl++])
            else -> b.add(a[ptrr++])
        }
        i++
    }
    return isSaw()
}

fun judge(l: Int): Boolean{
    if(l == 1){
        b.clear()
        b.add(a.first())
        return true
    }
    val(l1, l2) = l / 2 to l / 2 + l % 2
    if(saw(l1, l2))
        return true
    if(l % 2 == 1 && saw(l2, l1))
        return true
    return false
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t){
        n = readLine()!!.toInt()
        a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        a.sort()
        var(lo, hi) = 1 to n
        while(lo < hi){
            val mid = (lo + hi) / 2 + (lo + hi) % 2
            if(judge(mid))
                lo = mid
            else
                hi = mid-1
        }
        judge(lo)
        println(lo)
        println(b.joinToString(separator = " "))
    }
}