
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static java.nio.file.Files.lines;
import static java.nio.file.Paths.get;
import static java.util.stream.Collectors.toList;

public class Program {
    public static void main (String... args) throws Exception {
        final List<String> lines = lines(get(args[0])).collect(toList());

        final var linesIterator = lines.iterator();

        final String first = linesIterator.next();

        final String[] bingoCalls = first.split(",");

        final List<Board> boards = new ArrayList<>();

        while(linesIterator.hasNext()) {
            final String line = linesIterator.next();
            assert line.isBlank();

            final Board board = new Board();
            for (int i = 0; i < 5; ++i)
            {
                board.numbers[i] = Arrays.stream(linesIterator.next().trim().split("\\s+"))
                    .mapToInt(Integer::parseInt)
                    .toArray();
            }
            boards.add(board);
        }

        for (Board b : boards ) {
            System.out.println(b);
        }
    }

    private static class Board {
        private int [][] numbers = new int[5][];


        @Override
        public String toString() {
            final StringBuffer sb = new StringBuffer();
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
    }
}
