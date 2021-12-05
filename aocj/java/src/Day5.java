import java.util.List;

import static java.nio.file.Files.lines;
import static java.nio.file.Paths.get;
import static java.util.stream.Collectors.toList;

public class Day5
{
    public static void main(String[] args) throws Exception
    {
        final List<String> lines = lines(get(args[0])).collect(toList());
        System.out.println(lines);
    }
}
