/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/*** DTB_USER_CODE_START vvv Add file header below vvv ***/
/*
 *      $XConsortium: proj_stubs.c /main/3 1995/11/06 17:46:46 rswiston $
 *
 * @(#)proj_stubs.c	1.29 09 Jan 1995 cde_app_builder/src/ab
 *
 *      RESTRICTED CONFIDENTIAL INFORMATION:
 *
 *      The information in this document is subject to special
 *      restrictions in a confidential disclosure agreement between
 *      HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *      document outside HP, IBM, Sun, USL, SCO, or Univel without
 *      Sun's specific written approval.  This document and all copies
 *      and derivative works thereof must be returned or destroyed at
 *      Sun's request.
 *
 *      Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 */

/*** DTB_USER_CODE_END   ^^^ Add file header above ^^^ ***/

/*
 * File: proj_stubs.c
 * Contains: Module callbacks and connection functions
 *
 * This file was generated by dtcodegen, from module proj
 *
 * Any text may be added between the DTB_USER_CODE_START and
 * DTB_USER_CODE_END comments (even non-C code). Descriptive comments
 * are provided only as an aid.
 *
 *  ** EDIT ONLY WITHIN SECTIONS MARKED WITH DTB_USER_CODE COMMENTS.  **
 *  ** ALL OTHER MODIFICATIONS WILL BE OVERWRITTEN. DO NOT MODIFY OR  **
 *  ** DELETE THE GENERATED COMMENTS!                                 **
 */

#include <stdio.h>
#include <Xm/Xm.h>
#include "dtb_utils.h"
#include "dtbuilder.h"
#include "proj_ui.h"


/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All necessary header files have been included.
 ***
 *** Add include files, types, macros, externs, and user functions here.
 ***/

#include <sys/param.h>
#include "dtbuilder.h"
#include "proj_ui.h"
#include <ab_private/brwsP.h>
#include <ab_private/projP.h> 
#include <ab_private/ab.h>
#include <ab_private/abobj.h>
#include <ab_private/abobj_set.h>
#include <ab_private/ui_util.h>
#include <ab_private/trav.h>
#include <ab_private/bil.h>
#include "dtb_utils.h"

static int	select_fn(
		    VNode	module
		);

static int
select_fn(
    VNode	module
)
{
    if (BRWS_NODE_STATE_IS_SET(module, BRWS_NODE_SELECTED))
	return (1);

    return (0);
}

/*
 * Declarations of global widgets used by callbacks.
 */

char	Buf[MAXPATHLEN];	/* Work buffer */

/*
 * End declarations of global widgets
 */


/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/



void 
proj_proj_help_menu_Overview_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    dtb_show_help_volume_info("AppBuilder", "ABProjOrg");
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
proj_proj_help_menu_Reference_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    dtb_show_help_volume_info("AppBuilder", "ABProjOrg");
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
proj_proj_help_menu_Tasks_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    dtb_show_help_volume_info("AppBuilder", "ABManagingProject");
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
proj_proj_help_menu_Using_Help_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    dtb_show_help_volume_info("Help4Help", "_hometopic");
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
proj_proj_help_menu_On_Item_item_CB1(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    dtb_do_onitem_help();
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_save_mod_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr		v = NULL;
    VNode	*selected_nodes = NULL;
    VMethods	m;
    int		num_selected = 0,
		i;
    AB_OBJ	*obj;
    STRING	file = NULL;
    BOOL	read_OK = FALSE, write_OK = FALSE;
    int		rc = 0;
    char	mod_dir[MAXPATHLEN];
    char	help_buf[MAXPATHLEN];

    *mod_dir = 0;
    *help_buf = 0;
    XtVaGetValues(widget, XmNuserData, &v, NULL); 
    
    if (!v)
	return;
    
    if (!(m = v->methods))
	return;
    
    /*
     * Get nodes that are selected
     */
    vwr_get_cond(v->current_tree, &selected_nodes, 
			&num_selected, select_fn);
    
    if (num_selected == 0)
	return;

    obj = (AB_OBJ *)selected_nodes[0]->obj_data;

    file = obj_get_file(obj);
    /* The file has not been saved yet */
    if (file == NULL)
    {
        projP_show_save_as_bil_chooser(AB_toplevel, obj);
    }
    else
    {
	/* The file has been saved before.  Check to make
	 * sure that it still has write permission.
	 */
        if (obj_has_flag(obj, SaveNeededFlag))
        {
            /* Check if we're allowed to write to the directory
             * specified for the module file.
             */
            util_get_dir_name_from_path(file, mod_dir, MAXPATHLEN);
            rc = abio_access_file(mod_dir, &read_OK, &write_OK);
	    if (rc == 0)
            {
		if (write_OK)
            	{
		    abio_access_file(file, &read_OK, &write_OK);
	    	    if (write_OK)
	    	    {
			rc = bil_save_tree(obj, file, NULL, 
				BIL_SAVE_FILE_PER_MODULE);
			if (rc < 0)
		 	{
			    util_print_error(rc, file);
			}
		        else
		        {
			    vwr_init_elements(selected_nodes[0]);
			    brws_update_node(obj);
			    erase_viewer(v);
			    draw_viewer(v);
		        }
		    }
	            else
	            {
			sprintf(Buf, catgets(Dtb_project_catd, 100, 10,
			    "The file %s is a read-only file.\nCannot save edits."), file);
			util_set_help_data(catgets(Dtb_project_catd, 100, 81,
				"The changes that were made cannot be saved\nbecause you do not have permission to write\nto the file."),
				NULL, NULL);
			util_printf_err(Buf);
	    	    }
		}
		else
		{   
		    sprintf(Buf, catgets(Dtb_project_catd, 100, 76,
			"Cannot save module to \"%s\".\n\"%s\" does not have write permission."), mod_dir, mod_dir);
		    sprintf(help_buf, catgets(Dtb_project_catd, 100, 82,
			"You do not have permission to write to the\ndirectory \"%s\"."), mod_dir);
		    util_set_help_data(help_buf, NULL, NULL);
                    util_printf_err(Buf);
            	}
	    }
	    else
    	    {
		util_dprintf(1, "Error in accessing \"%s\".", mod_dir);
	    }
	}
    }

    /*
     * Free up node list if it contained anything
     */
    if (selected_nodes)
	free((char *)selected_nodes);

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_save_as_mod_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         v = NULL;
    VNode       *selected_nodes = NULL;
    VMethods    m;
    int         num_selected = 0,
                i;
    AB_OBJ      *obj;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)
        return;

    if (!(m = v->methods))
        return;

    /*
     * Get nodes that are selected
     */
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);
    if (num_selected == 0)
        return;

    obj = (AB_OBJ *)selected_nodes[0]->obj_data;

    projP_show_save_as_bil_chooser(AB_toplevel, obj);

    if (selected_nodes)
        free((char *)selected_nodes);

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_show_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         v = NULL;
    VNode       *selected_nodes = NULL;
    VMethods    m;
    int         num_selected = 0, i;
    ABObj       obj;
    BOOL	FirstShown = TRUE;
    AB_TRAVERSAL trav;
    ABObj       winobj;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)
        return;

    if (!(m = v->methods))
        return;

    /*
     * Get nodes that are selected
     */
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);
    if (num_selected == 0)
        return;

    /*
     * Set busy cursor before this potentially
     * lengthy operation
     */
    ab_set_busy_cursor(TRUE);

    for (i=0; i<num_selected; i++)
    {
        obj = (AB_OBJ *)selected_nodes[i]->obj_data;

	/* If the module is already showing, then
	 * make all of its windows come to the fore-
	 * ground.
	 */
	if (obj_has_flag(obj, MappedFlag))
	{
	    for (trav_open(&trav, obj, AB_TRAV_WINDOWS);
		(winobj = trav_next(&trav)) != NULL; )
	    {
		if (obj_has_flag(winobj, MappedFlag))
		    ui_win_front(objxm_get_widget(winobj));
	    }
	    trav_close(&trav);
	}
        else if( abobj_show_tree(obj, TRUE) == -1 )
        {
            if (util_get_verbosity() > 0)
                fprintf(stderr,"show_proc: error in abobj_show_tree\n");
	    break;
        }

	if (FirstShown)
	{
	    proj_set_cur_module(obj);
	    FirstShown = FALSE;
	}
    }

    /*
     * Unset busy cursor
     */
    ab_set_busy_cursor(FALSE);

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_hide_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         v = NULL;
    VNode       *selected_nodes = NULL;
    VMethods    m;
    int         num_selected = 0, i;
    ABObj       obj = NULL;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)
        return;

    if (!(m = v->methods))
        return;

    /*
     * Get nodes that are selected
     */  
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);
    if (num_selected == 0)
        return;

    for (i=0; i<num_selected; i++)
    {
        obj = (AB_OBJ *)selected_nodes[i]->obj_data;
        if( abobj_hide_tree(obj) == -1 )
        {
            if (util_get_verbosity() > 0)
                fprintf(stderr,"hide_proc: error in abobj_hide_tree\n");
        }
	if (obj == proj_get_cur_module())
	{
	    proj_set_cur_module(NULL);
	}
	    
    }

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_browse_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         v = NULL;
    VNode       *selected_nodes = NULL;
    VMethods    m;
    int         num_selected = 0,
                i;
    ABBrowser	cur_b;
    AB_OBJ  	*module;
    Boolean	hidden_modules = False;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)
        return;

    if (!(m = v->methods))
        return;

    /*
     * Get nodes that are selected
     */  
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);

    if (num_selected == 0)
	return;

    for (i = 0; i < num_selected; ++i)
    {
	ABSelectedRec	sel;

        module = (AB_OBJ *)selected_nodes[i]->obj_data;

	if (!obj_has_flag(module, MappedFlag))
	{
	    hidden_modules = True;
	    continue;
	}

        /*
         * Search for browser containing module
         */
        cur_b = brws_get_browser_for_obj(module);

        /*
         * Get selected objects in this module
         */
        abobj_get_selected(module, False, False, &sel);

        /*
         * Center view on first object in sel.list
         */
        if (sel.count > 0)
        {
            brws_center_on_obj(cur_b, sel.list[0]);
            util_free(sel.list);
        }

	/*
	 * Map browser that was found
	 */
	brws_popup(cur_b);
    }

    if (hidden_modules)
    {
	dtb_proj_brws_mod_msg_initialize(&dtb_proj_brws_mod_msg);
	dtb_show_message(dtb_get_toplevel_widget(),
		&dtb_proj_brws_mod_msg, NULL, NULL);
    }

    if (selected_nodes)
	free((char *)selected_nodes);
    

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_remove_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         	v = NULL;
    VNode       	*selected_nodes = NULL;
    VMethods    	m = NULL;
    int         	num_selected = 0, i, save_count = 0;
    ABObj       	obj = NULL;
    ABObj		proj = proj_get_project();
    DTB_MODAL_ANSWER	answer = DTB_ANSWER_NONE;
    int			len = 0;
    STRING		init_msg = NULL;
    STRING		wrnmsg = NULL;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)
        return;

    if (!(m = v->methods))
        return;
 
    /*
     * Get nodes that are selected
     */  
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);
    if (num_selected == 0)
        return;

    /* Before destroying the module, check if there are any
     * unsaved edits.  If so, post a modal dialog.
     */
    for (i=0; i<num_selected; i++)
    {
        obj = (AB_OBJ *)selected_nodes[i]->obj_data;
        if (obj_has_flag( obj, SaveNeededFlag) )
	{
	    STRING	name = obj_get_name(obj);
	    len = len + strlen(name) + 2;
            /*
             * Is this the first module with unsaved edits?
             * If so, initialize the notice message.
             */
            if (save_count == 0)
            { 
                /* The first thing in the message is 
		 * some general text.
		 */
                init_msg = catgets(Dtb_project_catd, 100, 68,
                        "The following module(s) have unsaved edits. Removing the\nmodule(s) from the project will discard your changes.\nPlease confirm.");

                /* If we have an old buffer lying around, free it */
                if (wrnmsg != (STRING) NULL)
                    util_free(wrnmsg);
 
                /* Now create a new buffer of the proper size */
                len = strlen(init_msg) + strlen(name) + 2;
                wrnmsg = (STRING) util_malloc(len);
                sprintf(wrnmsg, "%s\n\n%s", init_msg, name);
	    }
	    else
	    {
                wrnmsg = (STRING) realloc(wrnmsg, len);
                strcat(wrnmsg, "\n");
                strcat(wrnmsg, name);
	    }
	    save_count++;
	}
    }

    if (!util_strempty(wrnmsg))
    {
	XmString	xm_buf = NULL;
        xm_buf = XmStringCreateLocalized(wrnmsg);
	dtb_proj_del_mod_msg_initialize(&dtb_proj_del_mod_msg);
	answer = dtb_show_modal_message(XtParent(AB_proj_window),
			&dtb_proj_del_mod_msg, xm_buf, NULL, NULL);
        XmStringFree(xm_buf);
        util_free(wrnmsg);
    }

    /* If there were unsaved edits and the user has confirmed
     * discarding them OR if there were no unsaved edits, destroy
     * the selected module(s), set the SaveNeededFlag on the
     * project, and update the browser and project window.
     */  
    if (answer == DTB_ANSWER_ACTION1 || answer == DTB_ANSWER_NONE)
    {
	ab_set_busy_cursor(TRUE);
	ui_sync_display_of_widget(AB_toplevel);

	for (i=0; i<num_selected; i++)
	{
            obj = (AB_OBJ *)selected_nodes[i]->obj_data;

	    /* If the module destroyed was the current module,
	     * then set the new default module to NONE.
	     */
	    if (obj == proj_get_cur_module())
		proj_set_cur_module(NULL);

	    obj_destroy(obj);
	}
	ab_set_busy_cursor(FALSE);
        abobj_set_save_needed(proj, TRUE); 
	projP_update_menu_items(0, 0);
    }
    

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_repaint(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr                 v = NULL;
    VMethods            m;

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    m = v->methods;

    (*m->render_tree)(v->current_tree);


    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_set_userdata(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    DtbProjProjMainInfo	dtbSource = (DtbProjProjMainInfo)callData;
    
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    XtVaSetValues(widget, XmNuserData, (XtPointer)Proj_viewer, NULL);

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
projP_export_mod_proc(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/

    Vwr         v = NULL;
    VNode       *selected_nodes = NULL;
    VMethods    m;
    int         num_selected = 0;
    ABObj       obj;

    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/

    XtVaGetValues(widget, XmNuserData, &v, NULL);

    if (!v)                                       
        return;

    if (!(m = v->methods))
        return;

    /*          
     * Get nodes that are selected
     */
    vwr_get_cond(v->current_tree, &selected_nodes,
                        &num_selected, select_fn);

    if (num_selected == 0)                         
        return;
 
    obj = (AB_OBJ *)selected_nodes[0]->obj_data;
    proj_show_export_bil_chooser(AB_proj_window, obj);

    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}


void 
close_proj_win(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
)
{
    /*** DTB_USER_CODE_START vvv Add C variables and code below vvv ***/
    /*** DTB_USER_CODE_END   ^^^ Add C variables and code above ^^^ ***/
    
    /*** DTB_USER_CODE_START vvv Add C code below vvv ***/
    DtbProjProjMainInfo		proj_win =
				(DtbProjProjMainInfo) clientData;

    XtPopdown(ui_get_ancestor_shell(proj_win->proj_main));

    /*** DTB_USER_CODE_END   ^^^ Add C code above ^^^ ***/
}



/**************************************************************************
 *** DTB_USER_CODE_START
 ***
 *** All automatically-generated data and functions have been defined.
 ***
 *** Add new functions here, or at the top of the file.
 ***/
/*** DTB_USER_CODE_END
 ***
 *** End of user code section
 ***
 **************************************************************************/


