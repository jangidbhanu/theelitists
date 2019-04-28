$(document).ready(function() {
    $(this).scrollTop(0);
});

$(function() {
    $(document).scroll(function() {
        var nav = $(".navbar");
        nav.toggleClass('navbarscrolled', $(this).scrollTop() > nav.height());

    });
});

function menu() {
    $(".listmenu").toggleClass('menu');
    $(".line").css('color','#701e0f');
    $(".caps").css('color','#701e0f');

}