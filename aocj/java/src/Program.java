
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import static java.nio.file.Files.lines;
import static java.nio.file.Paths.get;
import static java.util.stream.Collectors.toList;

public class Program
{
    public static void main (String... args) throws Exception
    {
        final List<String> lines = lines(get(args[0])).collect(toList());
        final var linesIterator = lines.iterator();

        final String first = linesIterator.next();
        final int [] calls = Arrays.stream(first.split(","))
            .mapToInt(Integer::parseInt)
            .toArray();

        final List<Board> boards = new ArrayList<>();
        while(linesIterator.hasNext()) {
            linesIterator.next();// lets just say the inputs are clean
            assert linesIterator.hasNext();

            boards.add(Board.readBoard(linesIterator));
        }

        for (int call : calls) {
            final Iterator<Board> iterator = boards.iterator();

            while (iterator.hasNext())
            {
                final Board b = iterator.next();
                b.markNumber(call);
                if (b.isSolved())
                {
                    iterator.remove();
                    System.out.println(b.getScore() * call);
                }
            }
        }
    }

    private static class Board
    {
        private final int [][] numbers = new int[5][];

        private static Board readBoard(Iterator<String> linesIterator) {
            final Board ret = new Board();
            for (int i = 0; i < 5; ++i)
            {
                ret.numbers[i] = Arrays.stream(linesIterator.next().trim().split("\\s+"))
                    .mapToInt(Integer::parseInt)
                    .toArray();
            }
            return ret;
        }

        void markNumber(int call)
        {
            for (int i = 0; i < numbers.length; ++i) {
                final int[] line = numbers[i];
                for (int j = 0; j < line.length; ++j)
                {
                    if(numbers[i][j] == call)
                    {
                        numbers[i][j] = -1;
                    }
                }
            }
        }

        boolean isSolved()
        {
            for (int [] line : numbers)
            {
                if (Arrays.stream(line).sum() == -5)
                {
                    return true;
                }
            }

            for (int r = 0; r < numbers[0].length; r++) // omg
            {
                int sum = 0;
                for (int[] number : numbers) {
                    sum += number[r];
                }
                if (sum == -5)
                {
                    return true;
                }
            }

            return false;
        }

        @Override
        public String toString()
        {
            final StringBuilder sb = new StringBuilder();
            for (int [] line : numbers)
            {
                for (int i : line)
                {
                    sb.append(i);
                    sb.append(" ");
                }
                sb.append(System.lineSeparator());
            }
            return sb.toString();
        }

        public long getScore() {
            long ret = 0L;

            for (int [] line : numbers)
            {
                for (int n : line)
                {
                    if (n > -1)
                    {
                        ret += n;
                    }
                }
            }
            return ret;
        }
    }
}
