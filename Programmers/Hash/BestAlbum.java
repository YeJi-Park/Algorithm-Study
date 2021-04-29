package programmers.Hash;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import static java.util.stream.Collectors.*;

public class BestAlbum {
	class Music implements Comparable<Music>{
		
		private String genre;
		private int number;
		private int plays;
		
		public Music(String genre, int number, int plays) {
			this.genre = genre;
			this.number = number;
			this.plays = plays;
		}

		@Override
		public int compareTo(Music o) {
			int result = Integer.compare(plays, o.plays);
			if(result == 0) {
				result = Integer.compare(number, o.number);
			}
			return result;
		}
	}
	
    public int[] solution(String[] genres, int[] plays) {
        List<Music> musics = new ArrayList<>();
        
        for(int i=0; i<genres.length; i++) {
        	musics.add(new Music(genres[i], i, plays[i]));
        }
        
        Map<String, List<Music>> genreMusic = musics.stream()
        										.collect(groupingBy(m->m.genre, toList()));
        Map<String, Integer> genrePlays = musics.stream()
											.collect(groupingBy(m->m.genre, summingInt(m->m.plays)));
        
        List<Map.Entry<String, Integer>> entries = new LinkedList<>(genrePlays.entrySet());
        Collections.sort(entries, Collections.reverseOrder((o1, o2) -> o1.getValue().compareTo(o2.getValue())));
        
        genreMusic.values().forEach(l-> Collections.sort(l, Collections.reverseOrder()) );
        
        List<Integer> ans = new ArrayList<>();
        
        entries.forEach(e->{
        	List<Music> l = genreMusic.get(e.getKey());
        	ans.add(l.get(0).number);
        	if(l.size()>1) ans.add(l.get(1).number);
        });
        
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
