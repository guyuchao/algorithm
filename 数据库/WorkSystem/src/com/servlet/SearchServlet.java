package com.servlet;

import java.io.IOException;
import com.bean.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class SearchServlet extends HttpServlet{
	protected void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {  
		request.setCharacterEncoding("utf-8");
		try{
			HttpSession session=request.getSession();
			int wno=(int)session.getAttribute("wno");
			ArrayList<Extraworkinfo> info_list=new ArrayList<Extraworkinfo>();
			
			String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
			String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=WorkExtraDB";
			String userName="sa";
			String userPwd="guyuchao";
			Connection dbConn=null;
			dbConn= DriverManager.getConnection(dbURL,userName,userPwd);
			PreparedStatement ps;
			String sql="select w1.wname Ա����,ex.wtype �Ӱ�����,ex.workdate ����Ӱ�����,ex.timeb �Ӱ࿪ʼʱ��,ex.timee �Ӱ����ʱ��,ex.confirmstatus ���״̬,w2.wname ����� from extraworkinfo ex, worker w1, worker w2 where w1.wno=? and ex.wno=w1.wno and ex.confirmwno=w2.wno order by ex.workdate desc";
			ps=dbConn.prepareStatement(sql);
			ps.setInt(1, wno);
			
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
				Extraworkinfo info=new Extraworkinfo();
				info.setName(rs.getString("Ա����"));
				info.setType(rs.getInt("�Ӱ�����"));
				info.setDate(rs.getDate("����Ӱ�����").toString());
				info.setTimeb(rs.getTime("�Ӱ࿪ʼʱ��").toString());
				info.setTimee(rs.getTime("�Ӱ����ʱ��").toString());
				if(rs.getBoolean("���״̬")==false){
					info.setConfirmstatus("δͨ��");
				}
				else{
					info.setConfirmstatus("��ͨ��");
				}
				info.setPname(rs.getString("�����"));
				info_list.add(info);
			}
			
			request.setAttribute("result", info_list);
			ps.close();  
	        dbConn.close();
            //�ر�����
            request.getRequestDispatcher("searchinfo.jsp").forward(request, response);
           	
		} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}  
	  
    protected void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException, IOException {  
        doGet(request, response);  
    }  
}
