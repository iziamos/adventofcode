

import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Objects;
import java.util.Set;

import static java.nio.file.Files.lines;
import static java.nio.file.Paths.get;
import static java.util.stream.Collectors.toList;

public class Day5
{
    public static void main(String[] args) throws Exception
    {
        int blah[][] = new int [1000][1000];

        final List<String> lines = lines(get(args[0])).collect(toList());
        final List<Line> b = lines.stream()
            .map((String input) -> Line.fromString(input, blah))
            .filter(Objects::nonNull)
            .collect(toList());

        final long score = Arrays.stream(blah)
            .flatMapToInt(Arrays::stream)
            .filter(i -> i > 1)
            .count();

        System.out.println(score);
    }

    private static class Line
    {
        private String id;
        private Set<Point> points = Collections.newSetFromMap(new LinkedHashMap<>());

        @Override
        public String toString() {
            return "Line{" +
                "id='" + id + '\'' +
                ", points=" + points +
                '}';
        }

        private static Line fromString(String input, int [][] blah)
        {
            final Line ret = new Line();
            ret.id = input;

            final String[] points = input.split(" -> ", 2);

            final int[] start = Arrays.stream(points[0].split(","))
                .mapToInt(Integer::parseInt).toArray();
            final int[] end = Arrays.stream(points[1].split(","))
                .mapToInt(Integer::parseInt).toArray();

            if (start[0] == end[0])
            {
                final int min = Math.min(start[1], end[1]);
                final int max = Math.max(start[1], end[1]);

                for (int i = min; i <= max; ++i)
                {
                    final Point p = new Point();
                    p.x = start[0];
                    p.y = i;
                    ret.points.add(p);
                    blah[p.x][p.y]++;
                }
                return ret;
            }
            else if (start[1] == end[1])
            {
                final int min = Math.min(start[0], end[0]);
                final int max = Math.max(start[0], end[0]);

                for (int i = min; i <= max; ++i)
                {
                    final Point p = new Point();
                    p.x = i;
                    p.y = start[1];
                    ret.points.add(p);
                    blah[p.x][p.y]++;
                }
                return ret;
            }
            else if((start[0] - end[0]) == (start[1] - end[1]))
            {
                final int min = Math.min(start[0], end[0]);
                final int max = Math.max(start[0], end[0]);


                int miny = Math.min(start[1],end[1]);

                for (int i = min; i <= max; ++i)
                {
                    final Point p = new Point();
                    p.x = i;
                    p.y = miny++;
                    ret.points.add(p);
                    blah[p.x][p.y]++;
                }
                return ret;
            }
            else if ((end[0] - start[0]) == (start[1] - end[1]))
            {
                final int min = Math.min(start[0], end[0]);
                final int max = Math.max(start[0], end[0]);

                int maxy = Math.max(start[1],end[1]);

                for (int i = min; i <= max; ++i)
                {
                    final Point p = new Point();
                    p.x = i;
                    p.y = maxy--;
                    ret.points.add(p);
                    blah[p.x][p.y]++;
                }
                return ret;
            }
            return null;
        }

        private static class Point
        {
            @Override
            public String toString() {
                return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
            }

            private int x;
            private int y;
        }
    }
}
