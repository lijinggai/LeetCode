class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, Comparator.comparingInt(o->o[0]));
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        int i = 0;
        int day = 1;
        int res = 0;
        while (i < events.length || !queue.isEmpty()) {
            // ��day���ܲμӵĻ���ȫ�����뵽���ȶ��У����ս���ʱ������
            while (i < events.length && events[i][0] == day) {
                queue.add(events[i][1]);
                i++;
            }
            // ���Ѿ������Ļ���ȫ��ɾ��
            while (!queue.isEmpty() && queue.peek() < day) {
                queue.poll();
            }
            // һ��ֻ�ܲμ�һ�����齫����ʱ������İ�����
            if (!queue.isEmpty()) {
                queue.poll();
                res++;
            }
            // ������һ��
            day++;
        }
        return res;
    }
}