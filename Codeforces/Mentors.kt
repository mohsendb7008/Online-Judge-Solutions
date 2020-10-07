fun main() {
    val(n, k) = readLine()!!.split(" ").map { it.toInt() }
    val skills = readLine()!!.split(" ").map { it.toInt() }
    val sortedSkills = skills.withIndex().sortedBy { it.value }
    val sortedMentors = Array(n) {(0 to 0) to sortedSkills[it].index}
    for(i in 1 until n) {
        if(sortedSkills[i].value == sortedSkills[i-1].value)
            sortedMentors[i] = (sortedMentors[i-1].first.first to sortedMentors[i-1].first.second + 1) to sortedSkills[i].index
        else
            sortedMentors[i] = (sortedMentors[i-1].first.first + sortedMentors[i-1].first.second + 1 to 0) to sortedSkills[i].index
    }
    val mentors = IntArray(n)
    sortedMentors.forEach {
        mentors[it.second] = it.first.first
    }
    repeat(k){
        val(x, y) = readLine()!!.split(" ").map { it.toInt() }
        if(skills[y-1] > skills[x-1])
            mentors[y-1]--
        if(skills[y-1] < skills[x-1])
            mentors[x-1]--
    }
    println(mentors.joinToString(" "))
}