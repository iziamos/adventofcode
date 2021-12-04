
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

        System.out.println(Arrays.toString(bingoCalls));
    }
}
