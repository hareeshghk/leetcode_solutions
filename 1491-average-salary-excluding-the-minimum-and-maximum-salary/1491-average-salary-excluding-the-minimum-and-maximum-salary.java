class Solution {
    public double average(int[] salary) {
        int totalSum, minSalary, maxSalary;
        
        if (salary.length <= 2) {
            return 0.0000;
        }
        
        totalSum = 0;
        minSalary = salary[0];
        maxSalary = salary[0];
        
        for (int sal : salary) {
            minSalary = Math.min(minSalary, sal);
            maxSalary = Math.max(maxSalary, sal);
            totalSum += sal;
        }
        
        totalSum -= minSalary;
        totalSum -= maxSalary;
        
        double answer = (totalSum*1.0000)/(salary.length-2);
        
        return answer;
    }
}