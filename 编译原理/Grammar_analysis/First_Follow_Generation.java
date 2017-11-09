package demo1;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.TreeSet;

public class First_Follow_Generation {
	private Map<String,TreeSet<String>> grammar;
	private Map<Integer,String> index_map; 
	private int cnt_derivation;
	private Map<String,HashSet<String>> FIRST;
	private Map<String,HashSet<String>> FOLLOW;
	public First_Follow_Generation(Left_recursion_removal lrr) {
		grammar=lrr.getGrammar();
		index_map=lrr.getIndex_map();
		cnt_derivation=lrr.getCnt_derivation();
		this.First_set_generate();
		this.Follow_set_generation();
		System.out.println(FOLLOW.toString());
	}
	
	private TreeSet<String> get_generation_set(int index){
		return grammar.get(index_map.get(index));
	}
	
	private boolean judge_change(String begin,String generation_left_word) {
		HashSet<String> left_first=FIRST.get(generation_left_word);
		if(left_first.isEmpty()) {
			return false;//还未做
		}
		else {//已做
			Integer size=FIRST.get(begin).size();
			HashSet<String> begin_first=(HashSet<String>) FIRST.get(begin).clone();
			begin_first.addAll(left_first);
			if(begin_first.size()==size) {//没有新的
				return false;
			}
			else {
				FIRST.remove(begin);
				FIRST.put(begin, begin_first);
				return true;
			}
		}
	}
	
	private boolean add_first(String begin,TreeSet<String> generation_set) {
		for(String item:generation_set) {
			String generation_left_word=item.split(" ")[0];//一个产生式按内容分割
			if(FIRST.containsKey(generation_left_word)) {//非终结符
				boolean change=judge_change(begin,generation_left_word);
				if(change==false) {
					//未改变
					continue;
				}
				else {
					return true;
				}
			}
			else {//终结符
				if(FIRST.get(begin).contains(generation_left_word)) {
					continue;//已存在first集里
				}
				else {
					FIRST.get(begin).add(generation_left_word);
					return true;
				}
			}
		}
		return false;
	}
	private void First_set_generate() {
		FIRST=new HashMap();
		for(Integer key:index_map.keySet()) {
			HashSet<String> tmp=new HashSet<String>();
			FIRST.put(index_map.get(key), tmp);//初始化first集
		}
		boolean is_change=false;
		do {
			is_change=false;
			for(int i=1;i<=cnt_derivation;i++) {
				String begin=index_map.get(i);//non-terminal
				TreeSet<String> generation_set=get_generation_set(i);//generation
				is_change=add_first(begin,generation_set);
				if(is_change==true) {
					//修改，重新循环
					break;
				}
				else {
					continue;
				}
			}
		}while(is_change);
	}

	
	//以上是first集的部分
	//下面是follow集的部分
	private boolean has_non_terminal(String begin) {
		TreeSet<String> set=grammar.get(begin);
		for(String item:set) {
			String[] tmp_str=item.split(" ");
			for(String str:tmp_str) {
				if(grammar.containsKey(str)) {
					return true;
				}
			}
		}
		return false;
	}
	private void Follow_set_generation() {
		 //文法的开始符号不直接推出终结符
		FOLLOW=new HashMap<String,HashSet<String>>();
		for(Integer key:index_map.keySet()) {
			if(has_non_terminal(index_map.get(key))) {
				HashSet<String> tmp=new HashSet<String>();
				tmp.add("$");//界符
				FOLLOW.put(index_map.get(key), tmp);
			}
			else {
				HashSet<String> tmp=new HashSet<String>();
				FOLLOW.put(index_map.get(key), tmp);
			}
		}
		//初始化
		boolean is_change=false;
		do {
			is_change=false;
			for(int i=1;i<=cnt_derivation;i++) {
				String begin=index_map.get(i);//non-terminal
				TreeSet<String> generation_set=get_generation_set(i);//generation
				is_change=add_follow(begin,generation_set);
				if(is_change==false) {
					continue;
				}
				else {
					break;
				}
			}
		}while(is_change);
		
	}
	private boolean judge_change_follow(String begin,String sentence) {
		String[] words=sentence.split(" ");
		for(int i=0;i<words.length-1;i++) {
			if(grammar.containsKey(words[i])&&grammar.containsKey(words[i+1])) {
				//非终结符
				HashSet<String> follow_i=(HashSet<String>) FOLLOW.get(words[i]).clone();
				int size=follow_i.size();
				HashSet<String> first_i1=(HashSet<String>) FIRST.get(words[i+1]).clone();
				
				if(first_i1.contains("#")) {
					follow_i.addAll(FOLLOW.get(begin));
					first_i1.remove("#");
				}
				
				follow_i.addAll(first_i1);
				if(follow_i.size()==size) {
					continue;
				}
				else {
					FOLLOW.remove(words[i]);
					FOLLOW.put(words[i], follow_i);
					return true;
				}
			}
		}
		if(grammar.containsKey(words[words.length-1])) {
			HashSet<String> follow_i=(HashSet<String>) FOLLOW.get(words[words.length-1]).clone();
			int size=follow_i.size();
			follow_i.addAll(FOLLOW.get(begin));
			if(follow_i.size()==size) {
				return false;
			}
			else {
				FOLLOW.remove(words[words.length-1]);
				FOLLOW.put(words[words.length-1], follow_i);
				return true;
			}
		}
		return false;
		
	}
	private boolean add_follow(String begin,TreeSet<String> generation_set) {
		for(String each_sentence:generation_set) {
			if(judge_change_follow(begin,each_sentence)==true) {
				return true;
			}
			else {
				continue;
			}
		}		
		return false;
	}
	
	
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String str[]=new String[3];
		str[0]="stmt_sequence->stmt stmt_seq'";
		str[1]="stmt_seq'->; stmt_sequence|#";
		str[2]="stmt->s";
		/*str[0]="expr->expr addop term | term";
		str[1]="addop->+|-";
		str[2]="term->term mulop factor|factor";
		str[3]="mulop->*";
		str[4]="factor->( expr )|number";*/
		new First_Follow_Generation(new Left_recursion_removal(str));
	}

}
