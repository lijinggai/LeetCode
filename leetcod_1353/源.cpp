class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, Comparator.comparingInt(o->o[0]));
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        int i = 0;
        int day = 1;
        int res = 0;
        while (i < events.length || !queue.isEmpty()) {
            // 将day天能参加的会议全部加入到优先队列，按照结束时间排序
            while (i < events.length && events[i][0] == day) {
                queue.add(events[i][1]);
                i++;
            }
            // 将已经结束的会议全部删掉
            while (!queue.isEmpty() && queue.peek() < day) {
                queue.poll();
            }
            // 一天只能参加一场会议将结束时间最早的安排了
            if (!queue.isEmpty()) {
                queue.poll();
                res++;
            }
            // 安排下一天
            day++;
        }
        return res;
    }
}