/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoncalv <lgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:24:29 by lgoncalv          #+#    #+#             */
/*   Updated: 2022/06/18 17:21:15 by lgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAPPING_H
# define KEY_MAPPING_H

typedef enum e_keyboard_key
{
	key_a		= 97,
	key_d		= 100,
	key_e		= 101,
	key_q		= 113,
	key_s		= 115,
	key_w		= 119,
	key_esc		= 65307,
	key_left	= 65361,
	key_up		= 65362,
	key_right	= 65363,
	key_down	= 65364
}	t_keyboard_key;

typedef enum e_event
{
	on_keydown		= 2,
	on_keyup		= 3,
	on_mousedown	= 4,
	on_mouseup		= 5,
	on_mousemove	= 6,
	on_expose		= 12,
	on_destroy		= 17
}	t_event;

typedef enum e_mask
{
	mask_no_event				= 0L,
	mask_key_press				= 1L<<0,
	mask_key_release			= 1L<<1,
	mask_button_press			= 1L<<2,
	mask_button_release			= 1L<<3,
	mask_enter_window			= 1L<<4,
	mask_leave_window			= 1L<<5,
	mask_pointer_motion			= 1L<<6,
	mask_pointer_motion_hint	= 1L<<7,
	mask_button_1_motion		= 1L<<8,
	mask_button_2_motion		= 1L<<9,
	mask_button_3_motion		= 1L<<10,
	mask_button_4_motion		= 1L<<11,
	mask_button_5_motion		= 1L<<12,
	mask_button_motion			= 1L<<13,
	mask_keymap_state			= 1L<<14,
	mask_exposure_mask			= 1L<<15,
	mask_visibility_change		= 1L<<16,
	mask_structure_notify		= 1L<<17,
	mask_resize_redirect		= 1L<<18,
	mask_substructure_notif		= 1L<<19,
	mask_substructure_redirect	= 1L<<20,
	mask_focus_change			= 1L<<21,
	mask_property_change		= 1L<<22,
	mask_colormap_change		= 1L<<23,
	mask_owner_grab_button		= 1L<<24
}	t_mask;

// sorce: https://harm-smits.github.io/42docs/libs/minilibx/events.html
#endif