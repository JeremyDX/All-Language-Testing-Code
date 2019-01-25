public class Main
{
	static final ReadWriteBuffer buffer = ReadWriteBuffer.read("Foundation.obj");	
	static Vertex[] vertices = new Vertex[16384];
	static final IndexList[] indexs = new IndexList[16384];
	static int vertex_index = 0;
	static int quad_index = 0;

	public static void main(String[] args) throws Exception
	{	
		StringBuilder sb = new StringBuilder();
		String[] split = buffer.ConvertToString(34).split("\n");
		
		sb.append("File: ").append(split[0].substring(1, split[0].length() - 2));
		for (int i = 4; i < split.length; ++i)
		{
			char  opcode = split[i].charAt(0);
			char opcode2 = split[i].charAt(1);

			if (opcode == 'v' && opcode2 == ' ')
			{
				String vertexs[] = (split[i].substring(2)).split(" ");
				float x = Float.parseFloat(vertexs[0]);
				float y = Float.parseFloat(vertexs[1]);
				float z = Float.parseFloat(vertexs[2]);
				vertices[vertex_index] = new Vertex();
				vertices[vertex_index].x = x;
				vertices[vertex_index].y = y;
				vertices[vertex_index].z = z;
				++vertex_index;
			}

			if (opcode == 'f' && opcode2 == ' ')
			{
				String s[] = (split[i].substring(2)).split(" ");
				int _1 = Integer.parseInt(s[0].substring(0, s[0].indexOf("/")));
				int _2 = Integer.parseInt(s[1].substring(0, s[1].indexOf("/")));
				int _3 = Integer.parseInt(s[2].substring(0, s[2].indexOf("/")));
				int _4 = Integer.parseInt(s[3].substring(0, s[3].indexOf("/")));
				indexs[quad_index] = new IndexList();
				indexs[quad_index]._1 = _1;
				indexs[quad_index]._2 = _2;
				indexs[quad_index]._3 = _3;
				indexs[quad_index]._4 = _4;
				++quad_index;
			}
		}

		sb.setLength(0);

//0, 1
//2
//  1
//2 3

		for (int i = 0; i < quad_index; ++i)
		{
			int a = indexs[i]._1 - 1;
			int b = indexs[i]._2 - 1;
			int c = indexs[i]._3 - 1;
			int d = indexs[i]._4 - 1;
			
			Vertex t1 = vertices[a];
			Vertex t2 = vertices[b];
			Vertex t3 = vertices[c];
			
			Vertex t4 = vertices[c];
			Vertex t5 = vertices[d];
			Vertex t6 = vertices[a];
		
			sb.append("\n\nvertsToDraw[++offset] = { ").append(t1.x).append(", ").append(t1.y).append(", ").append(t1.z).append(", C._1, C._2, C._3, 1.0f, 1.0f };");
			sb.append("\nvertsToDraw[++offset] = { ").append(t2.x).append(", ").append(t2.y).append(", ").append(t2.z).append(", C._1, C._2, C._3, 0.0f, 1.0f };");
			sb.append("\nvertsToDraw[++offset] = { ").append(t3.x).append(", ").append(t3.y).append(", ").append(t3.z).append(", C._1, C._2, C._3, 0.0f, 0.0f };");

			sb.append("\n\nvertsToDraw[++offset] = { ").append(t4.x).append(", ").append(t4.y).append(", ").append(t4.z).append(", C._1, C._2, C._3, 0.0f, 0.0f};");
			sb.append("\nvertsToDraw[++offset] = { ").append(t5.x).append(", ").append(t5.y).append(", ").append(t5.z).append(", C._1, C._2, C._3, 1.0f, 0.0f };");
			sb.append("\nvertsToDraw[++offset] = { ").append(t6.x).append(", ").append(t6.y).append(", ").append(t6.z).append(", C._1, C._2, C._3,1.0f, 1.0f};");
		}

		System.out.println(sb.toString());
	}
}

/*
'Foundation_1.blend'
# www.blender.org
mtllib Foundation.mtl
o Cube_Cube.002
v -0.549039 -0.100000 0.550959
v -0.549039 0.100000 0.550959
v -0.550959 -0.100000 -0.549039
v -0.550959 0.100000 -0.549039
v 0.550959 -0.100000 0.549039
v 0.550959 0.100000 0.549039
v 0.549039 -0.100000 -0.550959
v 0.549039 0.100000 -0.550959
vn -1.0000 0.0000 0.0017
vn -0.0017 0.0000 -1.0000
vn 1.0000 0.0000 -0.0017
vn 0.0017 0.0000 1.0000
vn 0.0000 -1.0000 0.0000
vn 0.0000 1.0000 0.0000
usemtl None
s off
f 1//1 2//1 4//1 3//1
f 3//2 4//2 8//2 7//2
f 7//3 8//3 6//3 5//3
f 5//4 6//4 2//4 1//4
f 3//5 7//5 5//5 1//5
f 8//6 4//6 2//6 6//6
*/